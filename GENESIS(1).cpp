#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXN 110
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

struct Network {
	struct Edge {
		int dest, cost, next;
		Edge (int dest, int cost, int next) : dest(dest), cost(cost), next(next) {
		}
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

int N, k, M;
int in[MAXN], out[MAXN];

int main () {
	scan(N);
	for (int i=1; i<=N; i++) {
		in[i] = k++;
		out[i] = k++;
	}
	Network flow(k + 1, in[1], in[N]);
	for (int i=1, E; i<=N - 1; i++) {
		scan(E);
		flow.addEdge(in[i], out[i], E, 0);
	}
	scan(M);
	for (int i=0, u, v; i<M; i++) {
		scan(u); scan(v);
		flow.addEdge(out[u], in[v], INF, 0);
	}
	return !printf("%d\n", flow.getFlow());
}