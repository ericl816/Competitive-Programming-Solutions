#include <bits/stdc++.h>
#define ll long long
#define MAXN 10010
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define min(a, b) (a) < (b) ? (a) : (b)
#define max(a, b) (a) < (b) ? (b) : (a)
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define umii unordered_map<int, int>
#define mii map<int, int>
using namespace std;

struct State {
  int f, s;
  bool operator < (const State &e) const {
    return s > e.s;
  }
};

struct Edge {
	int idx, f, s;
};

int N, M, O, D, L, from[MAXN], to[MAXN], dist[MAXN], num[MAXN];
ll len[MAXN];
vector<Edge> adj[MAXN];
bool vis[MAXN], vis1[MAXN];
priority_queue<State> pq;
stack<int> st;

void SSSP (int src) {
	memset(dist, INF, sizeof(dist));
	memset(from, 0, sizeof(from));
	memset(to, 0, sizeof(to));
	dist[src] = 0;
	to[src] = 1;
	pq.push((State) {src, 0});
	while (!pq.empty()) {
		State curr = pq.top();
		pq.pop();
		if (dist[curr.f] < curr.s) continue;
		st.push(curr.f);
		for (size_t i=0; i<adj[curr.f].size(); i++) {
			Edge &next = adj[curr.f][i];
			if (dist[next.f] < dist[curr.f] + next.s) continue;
			if (dist[curr.f] + next.s < dist[next.f]) {
				dist[next.f] = dist[curr.f] + next.s;
				to[next.f] = 0;
				pq.push((State) {next.f, dist[next.f]});
			}
			to[next.f] = (to[next.f] + to[curr.f]) % MOD;
		}
	}
	while (!st.empty()) {
		int curr = st.top();
		st.pop();
		from[curr] = 1;
		for (size_t i=0; i<adj[curr].size(); i++) {
			Edge &next = adj[curr][i];
			if (dist[next.f] < dist[curr] + next.s) continue;
			from[curr] = (from[curr] + from[next.f]) % MOD;
			len[next.f] = (ll) ((ll) from[next.f] * (ll) to[curr]) % MOD;
			num[next.idx] = (int) (num[next.idx] + len[next.f]) % MOD;
		}
	}
}

inline void Solve () {
	for (int i=0; i<M; i++) printf("%d\n", (num[i] + MOD) % MOD);
}

int main () {
	scanf("%d %d", &N, &M);
	for (int i=0; i<M; i++) {
		scanf("%d %d %d", &O, &D, &L);
		O--; D--;
		adj[O].pb((Edge) {i, D, L});
	}
	for (int i=0; i<N; i++) SSSP(i);
	Solve();
	return 0;
}