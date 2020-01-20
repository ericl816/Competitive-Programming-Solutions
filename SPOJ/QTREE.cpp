#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXN 10010
#define SIZE 280
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define mii map<int, int>
#define umii unordered_map<int, int>
using namespace std;

// Need to use HLD + Segment Tree for this question

struct Node {
	int l, r, val;
};

// Define variables needed for HLD
int depth[MAXN], par[MAXN], subtree_size[MAXN], head[MAXN], chain[MAXN], vert[MAXN], weight[MAXN], ind[MAXN], arr[MAXN];
int idx, chainNum;
int T, N, a, b, c;
vector<pii> edgelist;
vector<pii> adj[MAXN];
string op;

struct Seg {
private:
	int N;
	vector<Node> tree;
	// int *arr;

public:
	Seg (int N) : N(N), tree(N << 2) {
		// arr = new int[N + 1];
		for (int i=0; i<N; i++) arr[ind[i]] = weight[i];
		Build(1, 1, N);
	}

	void Push_Up (int idx) {
		tree[idx].val = max(tree[idx << 1].val, tree[idx << 1 | 1].val);
	}

	void Build (int idx, int l, int r) {
		tree[idx].l = l;
		tree[idx].r = r;
		if (l == r) {
			tree[idx].val = arr[l];
			return;
		}
		int mid = (l + r) >> 1;
		Build(idx << 1, l, mid);
		Build(idx << 1 | 1, mid + 1, r);
		Push_Up(idx);
	}

	void Update (int idx, int l, int r, int val) {
		if (tree[idx].l > r || tree[idx].r < l) return;
		if (tree[idx].l == l && tree[idx].r == r) {
			tree[idx].val = val;
			return;
		}
		int mid = (l + r) >> 1;
		if (r <= mid) Update(idx << 1, l, r, val);
		else if (l > mid) Update(idx << 1 | 1, l, r, val);
		else {
			Update(idx << 1, l, mid, val);
			Update(idx << 1 | 1, mid + 1, r, val);
		}
		Push_Up(idx);
	}

	inline void Update (int idx, int l, int r, int ind, int val) {
		if (l > ind || r < ind) return;
		if (l == r) {
			tree[idx].val = val;
			return;
		}
		int mid = (l + r) >> 1;
		Update(idx << 1, l, mid, ind, val);
		Update(idx << 1 | 1, mid + 1, r, ind, val);
		Push_Up(idx);
	}

	int Query (int idx, int l, int r) {
		if (tree[idx].l > r || tree[idx].l < r) return -1;
		if (tree[idx].l >= l && tree[idx].r <= r) {
			return tree[idx].val;
		}
		int mid = (l + r) >> 1;
		if (r <= mid) return Query(idx << 1, l, r);
		else if (l > mid) return Query(idx << 1 | 1, l, r);
		return max(Query(idx << 1, l, mid), Query(idx << 1 | 1, mid + 1, r));
	}

	int Query (int idx, int l, int r, int l1, int r1) {
		if (l1 > r || l > r1) return -1;
		if (l >= l1 && r <= r1) return tree[idx].val;
		int mid = (l + r) >> 1;
		return max(Query(idx << 1, l, mid, l1, r1), Query(idx << 1 | 1, mid + 1, r, l1, r1));
	}
} *seg;

// Seg seg(MAXN);

// HLD Code Portion!!!
/*********************************************************************************/

// @param val = depth of chain
inline void DFS (int node, int prev, int val) {
	depth[node] = val;
	par[node] = prev;
	subtree_size[node] = 1;
	for (size_t i=0; i<adj[node].size(); i++) {
		pii &next = adj[node][i];
		if (next.f == prev) continue;
		weight[next.f] = next.s;
		DFS(next.f, node, val + 1);
		subtree_size[node] += subtree_size[next.f];
	}
}

inline void HLD (int node, int prev) {
	if (head[chainNum] == -1) head[chainNum] = node;
	chain[node] = chainNum;
	ind[node] = idx;
	vert[idx++] = node;
	int maxidx = -1;
	for (size_t i=0; i<adj[node].size(); i++) {
		pii &next = adj[node][i];
	 	if (next.f == prev) continue;
		if (maxidx == -1 || subtree_size[maxidx] < subtree_size[next.f]) maxidx = next.f;
	}
	if (~maxidx) HLD(maxidx, node);
	for (size_t i=0; i<adj[node].size(); i++) {
		pii &next = adj[node][i];
		if (next.f == prev || next.f == maxidx) continue;
		chainNum++;
		HLD(next.f, node);
	}
}

inline void InitHLD () {
	chainNum = 0;
	idx = 1;
	memset(head, -1, sizeof(head));
	DFS(0, -1, 0);
	HLD(0, -1);
	seg = new Seg(N);
}

inline int LCA (int x, int y) {
	while (chain[x] ^ chain[y]) {
		if (depth[head[chain[x]]] < depth[head[chain[y]]]) y = par[head[chain[y]]];
		else x = par[head[chain[x]]];
	}
	return depth[x] < depth[y] ? x : y;
}

inline void HLD_Update (int x, int y, int val) {
	if (par[x] == y) seg->Update(1, 1, N, ind[x], val);
	else if (par[y] == x) seg->Update(1, 1, N, ind[y], val);
	else assert(0);
}

// Query UP the chain to get the edge with the max weight!!!
inline int HLD_Query (int x, int y) {
	int maxedge = 0;
	while (chain[x] ^ chain[y]) {
		maxedge = max(maxedge, seg->Query(1, 1, N, ind[head[chain[x]]], ind[x]));
		x = par[head[chain[x]]];
	}
	if (x == y) return maxedge;
	maxedge = max(maxedge, seg->Query(1, 1, N, ind[y] + 1, ind[x]));
	return maxedge;
}

inline int Query_Path (int x, int y) {
	int lca = LCA(x, y);
	return max(HLD_Query(x, lca), HLD_Query(y, lca));
}

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while (T--) {
		cin >> N;
		for (int i=0; i<N; i++) adj[i].clear();
		edgelist.clear();
		for (int i=0; i<N - 1; i++) {
			cin >> a >> b >> c;
			a--; b--;
			adj[a].pb(mp(b, c));
			adj[b].pb(mp(a, c));
			edgelist.pb(mp(a, b));
		}
		InitHLD();
		while (1) {
			cin >> op;
			if (op == "CHANGE") {
				cin >> a >> b;
				a--;
				HLD_Update(edgelist[a].f, edgelist[a].s, b);
			}
			else if (op == "QUERY") {
				cin >> a >> b;
				a--; b--;
				cout << Query_Path(a, b) << "\n";
			}
			else if (op == "DONE") break;
			else assert(0);
		}
	}
	return 0;
}

/*
1

3
1 2 1
2 3 2
QUERY 1 2
CHANGE 1 3
QUERY 1 2
DONE
