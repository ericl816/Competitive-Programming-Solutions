#include <bits/stdc++.h>
#define ll long long
#define MAXN 100010
#define INF 0x3f3f3f3f3f3f3f3f
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
using namespace std;

int N, Q, idx, x, l, r;
ll d[MAXN];
char op;

struct Node {
	ll l, r, sum, ans, lval, rval;
};

struct Seg {
private:
	int N;
	vector<Node> tree;

public:
	Seg(int N) : N(N), tree(N << 2) { }

	Node PushUp (Node l, Node r) {
		if (l.sum == -INF) return r;
		if (r.sum == -INF) return l;
		Node next;
		next.sum = l.sum + r.sum;

		next.lval = max(l.lval, l.sum + r.lval);
		next.rval = max(r.rval, r.sum + l.rval);

		next.ans = max(next.lval, next.rval);
		next.ans = max(next.ans, next.sum);
		next.ans = max(next.ans, l.rval + r.lval);
		next.ans = max(next.ans, l.ans);
		next.ans = max(next.ans, r.ans);

		/*
		next.ans = max(next.sum, max(l.ans, r.ans));
		next.lval = max(l.lval, l.sum + r.lval);
		next.rval = max(r.rval, r.sum + l.rval);
		next.ans = max(max(next.ans, l.rval + r.lval), max(next.lval, next.rval));
		*/
		return next;
	}

	void PushDown (int idx, ll val) {
		tree[idx].sum = tree[idx].ans = tree[idx].lval = tree[idx].rval = val;
	}

	void Build (int idx, int l, int r) {
		tree[idx].l = l;
		tree[idx].r = r;
		if (l ^ r) {
			int mid = (l + r) >> 1;
			Build(idx << 1, l, mid);
			Build(idx << 1 | 1, mid + 1, r);
			tree[idx] = PushUp(tree[idx << 1], tree[idx << 1 | 1]);
		}
		else PushDown(idx, d[l]);
	}

	void Update (int idx, int l, int r, int arridx) {
		if (l > arridx || r < arridx) return;
		if (l == r) {
			PushDown(idx, d[l]);
			return;
		}
		int mid = (l + r) >> 1;
		Update(idx << 1, l, mid, arridx);
		Update(idx << 1 | 1, mid + 1, r, arridx);
		tree[idx] = PushUp(tree[idx << 1], tree[idx << 1 | 1]);
	}

	Node Query (int idx, int l, int r, int l1, int r1) {
		if (r1 < l || l1 > r) return Node {-INF, -INF, -INF, -INF};
		if (l >= l1 && r <= r1) return tree[idx];
		int mid = (l + r) >> 1;
		return PushUp(Query(idx << 1, l, mid, l1, r1), Query(idx << 1 | 1, mid + 1, r, l1, r1));
	}
};

Seg tree(MAXN);

int main () {
	scanf("%d %d", &N, &Q);
	tree.Build(1, 1, N);
	for (int i=1; i<=N; i++) {
		scanf("%lld", &d[i]);
		tree.Update(1, 1, N, i);
	}
	while (Q--) {
		scanf(" %c", &op);
		if (op == 'S') {
			scanf("%d %d", &idx, &x);
			d[idx] = x;
			tree.Update(1, 1, N, idx);
		}
		else if (op == 'Q') {
			scanf("%d %d", &l, &r);
			printf("%lld\n", tree.Query(1, 1, N, l, r).ans);
		}
	}
	return 0;
}