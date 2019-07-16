#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXN 20010
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

// Computes the second-shortest route from s to t
struct Edge {
	int a, b, dist;
};

int N, M, A, B, L;
ll ans = INF;
vector<Edge> vec;
vector<pii> adj1[MAXN], adj2[MAXN];
queue<int> q;
bool vis[MAXN];
int length1[MAXN], length2[MAXN];

inline void SSSP (int node, int dist[], vector<pii> adj[]) {
	memset(vis, 0, sizeof(vis));
	vis[node] = 1;
	dist[node] = 0;
	q.push(node);
	while (!q.empty()) {
		int curr = q.front();
		q.pop();
		vis[curr] = 0;
		for (size_t i=0; i<adj[curr].size(); i++) {
			pii &next = adj[curr][i];
			if (dist[next.f] > dist[curr] + next.s) {
				dist[next.f] = dist[curr] + next.s;
				if (!vis[next.f]) {
					vis[next.f] = 1;
					q.push(next.f);
				}
			}
		}
	}
}

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for (int i=0; i<M; i++) {
		cin >> A >> B >> L;
		adj1[--A].pb(mp(--B, L));
		adj2[B].pb(mp(A, L));
		vec.pb((Edge) {A, B, L});
	}
	memset(length1, INF, sizeof(length1));
	memset(length2, INF, sizeof(length2));
	SSSP(0, length1, adj1);
	SSSP(N - 1, length2, adj2);
	for (size_t i=0; i<vec.size(); i++) {
		Edge &next = vec[i];
		int val = length1[next.a] + length2[next.b] + next.dist;
		if (val < ans && length1[N - 1] < val) ans = val;
	}
	cout << (ans == INF ? -1 : ans) << endl;
	return 0;
}