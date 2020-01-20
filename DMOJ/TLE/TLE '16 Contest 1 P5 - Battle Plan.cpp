#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXN 100010
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

struct Node {
	int l, r, minn;
} tree[MAXN << 2];

int N;
ll p[MAXN], d[MAXN], c[MAXN], cost[MAXN], depth[MAXN], currdepth[MAXN];
vi adj[MAXN];

inline void Push_Up (int idx) {
	tree[idx].minn = min(tree[idx << 1].minn, tree[idx << 1 | 1].minn);
}

inline void Build (int idx, int l, int r) {
	tree[idx].l = l;
	tree[idx].r = r;
	if (l == r) {
		tree[idx].minn = INF;
		return;
	}
	int mid = (l + r) >> 1;
	Build(idx << 1, l, mid);
	Build(idx << 1 | 1, mid + 1, r);
	Push_Up(idx);
}

inline void Update (int idx, int pos, int val) {
	if (tree[idx].l == tree[idx].r) {
		tree[idx].minn = val;
		return;
	}
	int mid = (tree[idx].l + tree[idx].r) >> 1;
	if (pos <= mid) Update(idx << 1, pos, val);
	else Update(idx << 1 | 1, pos, val);
	Push_Up(idx);
}

inline ll Query (int idx, int val) {
	if (val <= tree[idx].minn) return -INF;
	if (tree[idx].l == tree[idx].r) return tree[idx].l;
	if (val > tree[idx << 1 | 1].minn) return Query(idx << 1 | 1, val);
	else return Query(idx << 1, val);
}

inline void DFS (int idx, int node, int prev) {
	currdepth[idx] = node;
	if (node ^ N) {
		depth[idx] = depth[idx - 1] + d[node];
		int val = Query(1, c[node]);
		cost[node] = cost[currdepth[val]] + (ll) c[node] * abs(depth[idx] - depth[val]);
	}
	Update(1, idx, c[node]);
	for (size_t i=0; i<adj[node].size(); i++) {
		int &next = adj[node][i];
		if (next == prev) continue;
		DFS(idx + 1, next, node);
	}
	Update(1, idx, INF);
}

int main () {
	scan(N);
	for (int i=1; i<N; i++) {
		scan(p[i]); scan(d[i]); scan(c[i]);
		adj[p[i]].pb(i);
	}
	Build(1, 1, N);
	Update(1, 1, 0);
	DFS(1, N, -1);
	for (int i=1; i<=N - 1; i++) printf("%lld\n", cost[i]);
	return 0;
}