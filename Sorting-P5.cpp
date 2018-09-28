#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define ull unsigned long long
#define MAXN 200010
#define SIZE 18 // ceil(log(MAXN) / log(2))
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
#define println cout << "\n";
#ifdef DEBUG
	#define D(x...) printf(x)
#else
	#define D(x...)
#endif
using namespace std;

int N, Q, u, v;
int P[MAXN], XOR[1 << SIZE];

// DMOPC '18 Contest 1 P5 - Sorting
// The value of C is simply the highest bit in i XOR P, for i in [0, N)

struct Node {
	int l, r;
	ll val, lazy;
};

struct Seg {
private:
	int N;
	vector<Node> tree;

public:
	Seg (int N) : N(N), tree(N << 2) { }

	inline void Push_Up (int idx) {
		tree[idx].val = max(tree[idx << 1].val, tree[idx << 1 | 1].val);
	}

	inline void Build (int idx, int l, int r) {
		tree[idx].l = l, tree[idx].r = r;
		if (l == r) {
			tree[idx].val = XOR[P[l] ^ l];
			return;
		}
		int mid = (l + r) >> 1;
		Build(idx << 1, l, mid);
		Build(idx << 1 | 1, mid + 1, r);
		Push_Up(idx);
	}

	inline void Update (int idx, int l, int r, int ind) {
		if (l > ind || r < ind) return;
		if (l == r) {
			tree[idx].val = XOR[P[l] ^ l];
			return;
		}
		int mid = (l + r) >> 1;
		Update(idx << 1, l, mid, ind);
		Update(idx << 1 | 1, mid + 1, r, ind);
		Push_Up(idx);
	}

	inline int Query () {
		return tree[1].val;
	}
};

Seg tree(MAXN);

int main (int argc, char const *argv[]) {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> Q;
	for (int i=0; i<N; i++) cin >> P[i];
	for (int i=0; i<SIZE; i++) {
		// We have to consider all bits for i in [0, N)
		for (int j=1 << i; j<1 << (i + 1); j++) {
			XOR[j] = 1 << i;
		}
	}
	tree.Build(1, 0, N - 1);
	while (Q--) {
		cin >> u >> v;
		if (u ^ v) {
			swap(P[--u], P[--v]);
			tree.Update(1, 0, N - 1, u);
			tree.Update(1, 0, N - 1, v);
		}
		cout << tree.Query() << "\n";
	}
	return 0;
}

/* 
 * Look for:
 * the exact constraints (multiple sets are too slow for n=10^6 :( ) 
 * special cases (n=1?)
 * overflow (ll vs int?)
 * array bounds
 */