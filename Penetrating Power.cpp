#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
// #include <bits/stdc++.h>
#include "/Users/ericliu/Desktop/Competitive-Programming-Templates/stdc++.h"
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ull unsigned long long
#define MAXN 200010
#define INF 0x3f3f3f3f
using namespace std;

struct Node {
	int l, r;
	ull val, lazy;
};

struct Seg {
private:
	int N;
	vector<Node> tree;

public:
	Seg (int N) : N(N), tree(N << 2) { }

	inline void Push_Down (int idx) {
		if (tree[idx].l ^ tree[idx].r && tree[idx].lazy) {
			tree[idx << 1].lazy += tree[idx].lazy;
			tree[idx << 1].val += tree[idx].lazy;
			tree[idx << 1 | 1].lazy += tree[idx].lazy;
			tree[idx << 1 | 1].val += tree[idx].lazy;
			tree[idx].lazy = 0;
		}
	}

	inline void Push_Up (int idx) {
		tree[idx].val = max(tree[idx << 1].val, tree[idx << 1 | 1].val);
	}

	inline void Build (int idx, int l, int r) {
		tree[idx].l = l;
		tree[idx].r = r;
		if (l == r) {
			tree[idx].val = 0;
			tree[idx].lazy = 0;
			return;
		}
		int mid = (l + r) >> 1;
		Build(idx << 1, l, mid);
		Build(idx << 1 | 1, mid + 1, r);
	}

	inline void Update (int idx, int l, int r, int val) {
		Push_Down(idx);
		if (tree[idx].l > r || tree[idx].r < l) return;
		if (tree[idx].l >= l && tree[idx].r <= r) {
			tree[idx].val += val;
			tree[idx].lazy += val;
			return;
		}
		Update(idx << 1, l, r, val);
		Update(idx << 1 | 1, l, r, val);
		Push_Up(idx);
	}

	inline ull Query (int idx, int l, int r) {
		Push_Down(idx);
		if (tree[idx].l > r || tree[idx].r < l) return 0;
		if (tree[idx].l >= l && tree[idx].r <= r) return tree[idx].val;
		return max(Query(idx << 1, l, r), Query(idx << 1 | 1, l, r));
	}
};

int N, K, Q, query, P, V, idx, L, R;
Seg tree(MAXN);

int main() {
  scan(N);
  scan(K);
  scan(Q);
  tree.Build(1, 1, N);
	for (int i=0; i<Q; i++) {
		scan(query);
		if (!query) {
			scan(P);
			scan(V);
			idx = P - K + 2;
			tree.Update(1, min(idx, INF), P + 1, V);
		} 
		else if (query) {
			scan(L);
			scan(R);
			printf("%llu\n", tree.Query(1, min(L + 1, INF), min(R + 1, N)));
		}
	}
}