#include <bits/stdc++.h>
#define scan(x) do {while((x=getchar())<'0') ; for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0') ; } while(0)
char _;
#define INF 0x3f3f3f3f
using namespace std;

typedef unsigned long long ull;

struct Node {
public:
ull val, lazy;
int l, r;
};

struct Seg {
private:
	int N;
	vector<Node> tree;

public: 
	Seg(int N) : N(N), tree(N << 2) {}

  void PushUp (int idx) {
    tree[idx].val = max(tree[idx << 1].val, tree[idx << 1 | 1].val);
  }

  void PushDown (int idx) {
		if (tree[idx].l != tree[idx].r && tree[idx].lazy) {
			tree[idx << 1].val += tree[idx].lazy;
			tree[idx << 1].lazy += tree[idx].lazy;
			tree[idx << 1 | 1].val += tree[idx].lazy;
			tree[idx << 1 | 1].lazy += tree[idx].lazy;
			tree[idx].lazy = 0;
		}
  }

	void Build(int idx, int l, int r) {
		tree[idx] = Node {0, 0, l, r};
		if (l ^ r) {
		int mid = (l + r) >> 1;
		Build(idx << 1, l, mid);
		Build(idx << 1 | 1, mid + 1, r);
		}
	}

	void Update(int idx, int l, int r, ull val) {
		PushDown(idx);
		if (r < tree[idx].l || l > tree[idx].r) return;
		if (l <= tree[idx].l && r >= tree[idx].r) {
			tree[idx].val += val;
			tree[idx].lazy += val;
			return;
		}
		Update(idx << 1, l, r, val);
		Update(idx << 1 | 1, l, r, val);
		PushUp(idx);
	}

	ull Query(int idx, int l, int r) {
		PushDown(idx);
		if (l > r) swap(l, r);
		if (l <= r) {
		if (r < tree[idx].l || l > tree[idx].r) return 0;
		if (l <= tree[idx].l && r >= tree[idx].r) return tree[idx].val;
		return max(Query(idx << 1, l, r), Query(idx << 1 | 1, l, r));
		}
		else if (l > r || l >= N) return 0;
	}
};

int N, K, Q, query, P, V, idx, L, R;
Seg tree(200005);

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
			tree.Update(1, min(INF, idx), P + 1, V);
		} 
		else if (query) {
			scan(L);
			scan(R);
			printf("%llu\n", tree.Query(1, min(INF, L + 1), min(N, R + 1)));
		}
	}
}
