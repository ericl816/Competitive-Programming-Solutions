#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXN 300010
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

int N, M, A, B, cnt;
bool vis[MAXN], is_child[MAXN];
vi adj[MAXN];

inline void DFS (int node, int prev) {
	vis[node] = 1;
	is_child[node] = 1;
	for (size_t i=0; i<adj[node].size(); i++) {
		int &next = adj[node][i];
		if (next == prev) continue;
		DFS(next, node);
		is_child[node] &= (is_child[next] ^ 1);
	}
	if (is_child[node]) cnt++;
}

int main () {
	scan(N); scan(M);
	for (int i=0; i<M; i++) {
		scan(A); scan(B);
		adj[--A].pb(--B);
		adj[B].pb(A);
	}
	for (int i=0; i<N; i++) if (!vis[i]) DFS(i, -1);
	return !printf("%d\n", min(N - 2, cnt - 1));
}