#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXN 101
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
using namespace std;

struct Network {
	struct Edge {
		int dest, cost, next;
		Edge (int dest, int cost, int next) : dest(dest), cost(cost), next(next) { }
	};

	int N, src, sink;
	vector<int> last;
	vector<bool> vis;
	vector<Edge> e;

	Network (int N, int src, int sink) : N(N), src(src), sink(sink), last(N), vis(N) {
		fill(last.begin(), last.end(), -1);
	}

	void addEdge (int x, int y, int xy, int yx) {
		e.push_back(Edge(y, xy, last[x]));
		last[x] = e.size() - 1;
		e.push_back(Edge(x, yx, last[y]));
		last[y] = e.size() - 1;
	}

	int dfs (int curr, int flow) {
		vis[curr] = 1;

		if (curr == sink) {
			return flow;
		}

		for (int i = last[curr]; i != -1; i = e[i].next) {
			if (e[i].cost > 0 && !vis[e[i].dest]) {
				int res = dfs(e[i].dest, min(flow, e[i].cost));
				if (res > 0) {
					e[i].cost -= res;
					e[i ^ 1].cost += res;
					return res;
				}
			}
		}
		return 0;
	}

	int getFlow () {
		int res = 0, curr;
		fill(vis.begin(), vis.end(), 0);
		while ((curr = dfs(src, INF))) {
			res += curr;
			fill(vis.begin(), vis.end(), 0);
		}
		return res;
	}
};

int M, N, source, sink, idx = -1;
int in[MAXN][MAXN], out[MAXN][MAXN];
string grid[MAXN];

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> M >> N;
	for (int i=0; i<N; i++) {
		cin >> grid[i];
		for (int j=0; j<M; j++) {
			in[i][j] = ++idx;
			out[i][j] = ++idx;
		}
	}
	// source = N << 1 | 1;
	// sink = source + 1;
	source = ++idx;
	sink = ++idx;
	Network flow(idx + 1, source, sink);
	for (int i=0; i<N; i++) {
		if (grid[i][0] == '.') flow.addEdge(source, in[i][0], INF, 0);
		if (grid[i][M - 1] == '.') flow.addEdge(out[i][M - 1], sink, INF, 0);
	}
	for (int i=0; i<N; i++) {
		for (int j=0; j<M; j++) {
			if (grid[i][j] == '#') continue;
			flow.addEdge(in[i][j], out[i][j], 1, 0);
			// Move left
			if (j > 0 && grid[(i + 1) % N][j - 1] == '.') flow.addEdge(out[i][j], in[(i + 1) % N][j - 1], INF, 0);
			// Move right
			if (j < M - 1 && grid[(i + 1) % N][j + 1] == '.') flow.addEdge(out[i][j], in[(i + 1) % N][j + 1], INF, 0);
			// Stay
			if (grid[(i + 1) % N][j] == '.') flow.addEdge(out[i][j], in[(i + 1) % N][j], INF, 0);
			// Move down
			if (grid[(i + 2) % N][j] == '.') flow.addEdge(out[i][j], in[(i + 2) % N][j], INF, 0);
		}
	}
	cout << flow.getFlow() << "\n";
	return 0;
}