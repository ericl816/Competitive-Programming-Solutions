#include <bits/stdc++.h>
#define ll long long
#define MAXN 2010
#define INF 0x3f3f3f3f
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define mii map<int, int>
#define umii unordered_map<int, int>
using namespace std;

struct Edge {
	int a, x, y;
};

int N, M, T, a, b, x, y;
int indegree[MAXN];
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

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M >> T;
	for (int i=0; i<M; i++) {
		cin >> a >> b >> x >> y;
		if (a == N) continue;
		a--; b--;
		adj[a].pb((Edge) {b, x, y});
		indegree[b]++;
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
	cout << setprecision(10) << fixed << ex() << endl;
	return 0;
}