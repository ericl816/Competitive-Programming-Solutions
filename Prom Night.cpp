#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXM 110
#define MAXN 220
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

int N, M, T, id, a, b, ans;
int pre[MAXN];
bool ins[MAXM], vis[MAXN];
vi adj[MAXN];

// Hungarian algorithm solves the Maximum Bipartite Matching problem (assignment problem) in polynomial time and was developed by Harold Kuhn
// Time Complexity shuold be: O(N^3)
inline bool Hungarian (int src) {
	for (size_t i=0; i<adj[src].size(); i++) {
		int &next = adj[src][i];
		if (vis[next]) continue;
		vis[next] = 1;
		if (!pre[next] || Hungarian(pre[next])) return pre[next] = src;
	}
	return 0;
}

int main () {
	scan(N); scan(M); scan(T);
	for (int i=0; i<T; i++) {
		scan(id);
		ins[id] = 1;
	}
	for (int i=2; i<=N; i++) {
		scan(a);
		for (int j=0; j<a; j++) {
			scan(b);
			if (ins[b]) adj[i].pb(b + N);
		}
	}
	for (int i=1; i<=MAXN; i++) {
		memset(vis, 0, sizeof(vis));
		ans += Hungarian(i);
	}
	return !printf("%d\n", T - ans);
}