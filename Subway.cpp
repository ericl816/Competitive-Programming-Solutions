#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define ull unsigned long long
#define MAXN 2010
#define INF 0x3f3f3f3f
#define min(a, b) (a) < (b) ? (a) : (b)
#define max(a, b) (a) < (b) ? (b) : (a)
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define mii map<int, int>
#define umii unordered_map<int, int>
#define println cout << "\n";
#ifdef DEBUG
	#define D(x...) printf(x)
#else
	#define D(x...)
#endif
using namespace std;

struct Edge {
	int a, x, y;
};

int N, M, T, a, b, x, y;
int indeg[MAXN], outdeg[MAXN];
double num, denom;
double DP[MAXN][MAXN];
vector<Edge> adj[MAXN];

// Computes the chance of arriving on time
inline double f () {
	for (int i=0; i<=T; i++) denom += static_cast<double>(1.0 * DP[i][N - 1]);
	return denom;
}

// g() = f() * ex()
inline double g () {
	for (int i=0; i<=T; i++) num += static_cast<double>(1.0 * i * DP[i][N - 1]);
	return num;
}

// Computes the expected value of X/ans
inline double ex () {
	return static_cast<double>(1.0 * g() / f());
}

int main (int argc, char const *argv[]) {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M >> T;
	for (int i=0; i<M; i++) {
		cin >> a >> b >> x >> y;
		if (a == N) continue;
		adj[--a].pb((Edge) {--b, x, y});
		indeg[b]++;
		outdeg[a]++;
	}
	DP[0][0] = static_cast<double>(1);
	DP[1][0] = static_cast<double>(-1);
	for (int i=0; i<T; i++) {
		for (int j=0; j<N; j++) {
			for (size_t k=0; k<adj[j].size(); k++) {
				Edge &next = adj[j][k];
				double prob = static_cast<double>(1.0 * DP[i][j] / (adj[j].size() * (next.y - next.x + 1)));
				if (next.x + i <= T) {
					DP[next.x + i][next.a] += prob;
					if (next.y + i + 1 <= T) DP[next.y + i + 1][next.a] -= prob;
				}
			}
			DP[i + 1][j] += DP[i][j];
		}
	}
	cout << fixed << setprecision(10) << ex() << endl;
	return 0;
}

/* 
 * Look for:
 * the exact constraints (multiple sets are too slow for n=10^6 :( ) 
 * special cases (n=1?)
 * overflow (ll vs int?)
 * array bounds
 */