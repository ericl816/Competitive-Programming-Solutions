#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
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

int N, Q, x, y;
char op;
ll val, ans;
ll v[MAXN];

struct Node {
	int l, r;
	ll val;
};

struct Seg {
private:
	int N;
	vector<Node> seg;

public:
	Seg (int N) : N(N), seg(N << 2) { }

	void Push_Up (int idx) {
		seg[idx].val = seg[idx << 1].val & seg[idx << 1 | 1].val;
	}

	void Build (int idx, int l, int r) {
		seg[idx].l = l;
		seg[idx].r = r;
		if (l == r) {
			seg[idx].val = v[l];
			return;
		}
		int mid = (l + r) >> 1;
		Build(idx << 1, l, mid);
		Build(idx << 1 | 1, mid + 1, r);
		Push_Up(idx);
	}

	void Update (int idx, int l, int r, int ind, int val) {
		if (l > ind || r < ind) return;
		if (l == r) {
			seg[idx].val = val;
			return;
		}
		int mid = (l + r) >> 1;
		Update(idx << 1, l, mid, ind, val);
		Update(idx << 1 | 1, mid + 1, r, ind, val);
		Push_Up(idx);
	}

	ll Query (int idx, int l, int r, int l1, int r1) {
		if (l1 > r || r1 < l) return -1;
		if (l1 <= l && r <= r1) return seg[idx].val;
		int mid = (l + r) >> 1;
		return Query(idx << 1, l, mid, l1, r1) & Query(idx << 1 | 1, mid + 1, r, l1, r1);
	}
};

Seg tree(MAXN);

int main () {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> Q;
	for (int i=0; i<N; i++) cin >> v[i];
	tree.Build(1, 0, N - 1);
	for (int i=0; i<Q; i++) {
		cin >> op;
		if (op == 'U') {
			cin >> x >> val;
			--x;
			tree.Update(1, 0, N - 1, x, val);
		}
		else {
			cin >> x >> y >> val;
			--x; --y;
			cout << (val & tree.Query(1, 0, N - 1, x, y)) << "\n";
		}
	}
	return 0;
}