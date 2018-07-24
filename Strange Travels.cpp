#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXN 200010
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

int N, M, K;
int A[MAXN], B[MAXN], S[MAXN], dist1[MAXN], dist2[MAXN];
ll ans;
vi adj1[MAXN], adj2[MAXN];
queue<int> q;
bool vis[MAXN];

inline void SPFA (int src, int dist[], vi adj[MAXN]) {
	memset(vis, 0, sizeof(vis));
	dist[src] = 0;
	vis[src] = 1;
	q.push(src);
	while (!q.empty()) {
		int curr = q.front();
		q.pop();
		vis[curr] = 0;
		for (size_t i=0; i<adj[curr].size(); i++) {
			int &next = adj[curr][i];
			int nextcost = dist[curr] + 1;
			if (dist[next] > nextcost) {
				dist[next] = nextcost;
				if (!vis[next]) {
					vis[next] = 1;
					q.push(next);
				}
			}
		}
	}
}

int main () {
	scan(N); scan(M);
	for (int i=0; i<M; i++) {
		scan(A[i]); scan(B[i]);
		adj1[A[i]].pb(B[i]);
		adj2[B[i]].pb(A[i]);
	}
	memset(dist1, INF, sizeof(dist1));
	memset(dist2, INF, sizeof(dist2));
	SPFA(1, dist1, adj1);
	SPFA(1, dist2, adj2);
	scan(K);
	for (int i=0; i<K; i++) {
		scan(S[i]);
		if (~ans && dist1[S[i]] != INF && dist2[S[i]] != INF) ans += dist1[S[i]] + dist2[S[i]];
		else ans = -1;
	}
	return !printf("%lld\n", ans);
}