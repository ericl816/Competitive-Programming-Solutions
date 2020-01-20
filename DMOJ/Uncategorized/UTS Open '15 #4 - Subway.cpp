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
int indeg[MAXN], outdeg[MAXN];
double num, denom;
double DP[MAXN][MAXN];
vector<Edge> adj[MAXN];

inline double f () {
	for (int i=0; i<=T; i++) denom += 1.0 * DP[i][N - 1];
	return denom;
}

inline double g () {
	for (int i=0; i<=T; i++) num += 1.0 * i * DP[i][N - 1];
	return num;
}

inline double ex () {
	return 1.0 * g() / f();
}

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M >> T;
	for (int i=0; i<M; i++) {
		cin >> a >> b >> x >> y;
		if (a == N) continue;
		adj[--a].pb((Edge) {--b, x, y});
		indeg[b]++;
		outdeg[a]++;
	}
	DP[0][0] = 1.0;
	DP[1][0] = -1.0;
	for (int i=0; i<T; i++) {
		for (int j=0; j<N; j++) {
			for (size_t k=0; k<adj[j].size(); k++) {
				Edge &next = adj[j][k];
				double prob = 1.0 * DP[i][j] / (adj[j].size() * (next.y - next.x + 1));
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