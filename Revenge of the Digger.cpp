#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXM 1010
#define MAXN 10010
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
	vector<int> last, dist;
	vector<Edge> e;

	Network (int N, int src, int sink) : N(N), src(src), sink(sink), last(N), dist(N) {
		fill(last.begin(), last.end(), -1);
	}

	void addSink (int x) {
		sink = x;
	}

	void addEdge (int x, int y, int xy, int yx) {
		e.push_back(Edge(y, xy, last[x]));
		last[x] = e.size() - 1;
		e.push_back(Edge(x, yx, last[y]));
		last[y] = e.size() - 1;
	}

	bool getPath () {
		fill(dist.begin(), dist.end(), -1);
		queue<int> q;
		q.push(src);
		dist[src] = 0;
		while (!q.empty()) {
			int curr = q.front();
			q.pop();
			for (int i = last[curr]; i != -1; i = e[i].next) {
				if (e[i].cost > 0 && dist[e[i].dest] == -1) {
					dist[e[i].dest] = dist[curr] + 1;
					q.push(e[i].dest);
				}
			}
		}
		return dist[sink] != -1;
	}

	int dfs (int curr, int flow) {
		if (curr == sink) {
			return flow;
		}
		int ret = 0;
		for (int i = last[curr]; i != -1; i = e[i].next) {
			if (e[i].cost > 0 && dist[e[i].dest] == dist[curr] + 1) {
				int res = dfs(e[i].dest, min(flow, e[i].cost));
				ret += res;
				e[i].cost -= res;
				e[i ^ 1].cost += res;
				flow -= res;
				if (flow == 0) {
					break;
				}
			}
		}
		return ret;
	}

	int getFlow () {
		int res = 0;
		while (getPath()) {
			res += dfs(src, 1 << 30);
		}
		return res;
	}
};

int N, M, F, A, B, source, sink;

int main () {
	scan(N); scan(M);
	source = N << 1 | 1;
	sink = source + 1;
	Network flow(MAXN, 0, 0);
	for (int i=0; i<N; i++) {
		scan(F);
		flow.addEdge(i << 1, i << 1 | 1, F, 0); // Or: flow.addEdge(i, i + N, F, 0);
		if (F == 0) sink = i << 1, flow.addSink(sink); // Or: sink = i, flow.addSink(sink);
	}
	for (int i=0; i<M; i++) {
		scan(A); scan(B);
		A--; B--;
		flow.addEdge(A << 1 | 1, B << 1, INF, 0); // Or: flow.addEdge(A + N, B, INF, 0);
	}
	return !printf("%d\n", flow.getFlow());
}