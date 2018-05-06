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

/* 
 * Specifically, if you took the path starting from u and ending at v and wrote it into an array with Au as the first element and Av as the last,
 * then the jth value of this array must be congruent to j mod 2. That is, Aj % 2 = j
 * Surprisingly, this problem can be solved using Centroid Decomposition, but that seems overkill.
 * Instead, we can either solve it using Tree DP or by using Connected Components on the Path.
 * For the latter, we can simply store the nodes on the path in the array: idx[]
 */

int N, a, b, path_node;
ll ans;
int A[MAXN], subtree_size[MAXN], idx[MAXN];
bool vis[MAXN], parity[MAXN];
vi adj[MAXN];

inline void DFS (int node, int prev) {
	idx[node] = path_node;
	++subtree_size[path_node];
	for (size_t i=0; i<adj[node].size(); i++) {
		int &next = adj[node][i];
		if (~idx[next] || next == prev) continue;
		DFS(next, node);
	}
}

int main () {
	memset(idx, -1, sizeof(idx));
	scan(N);
	for (int i=0; i<N; i++) {
		scan(A[i]);
		parity[i] = A[i] & 1;
	}
	for (int i=1; i<N; i++) {
		scan(a); scan(b);
		if (parity[--a] ^ parity[--b]) {
			adj[a].pb(b);
			adj[b].pb(a);
		}
	}
	for (int i=0; i<N; i++) {
		if (!~idx[i]) {
			DFS(i, -1);
			path_node++;
		}
		ans += parity[i] ? subtree_size[idx[i]] : 0;
	}
	return !printf("%lld\n", ans);
}