#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define ull unsigned long long
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
#define println cout << "\n";
#ifdef DEBUG
	#define D(x...) printf(x)
#else
	#define D(x...)
#endif
using namespace std;

// Using Fermat's Little Theorem and Pascal's Binomial Expansion, the query: (A[l]^M + A[l + 1]^M + ... + A[r]^M) % M becomes (A[l] + A[l + 1] + ... + A[r]) % M

int N, M, Q, op, l, r, x;
ull a[MAXN];

struct Node {
    int l, r;
    ull val, lazy;
};

struct Seg {
private:
    int N;
    vector<Node> tree;

public:
    Seg(int N) : N(N), tree(N << 2) { }

    inline void Push_Up (int idx) {
        tree[idx].val = tree[idx << 1].val + tree[idx << 1 | 1].val;
    }

    inline void Push_Down (int idx) {
        if (tree[idx].lazy && tree[idx].l ^ tree[idx].r) {
            tree[idx << 1].val += tree[idx].lazy * (tree[idx << 1].r - tree[idx << 1].l + 1);
            tree[idx << 1].lazy += tree[idx].lazy;
            tree[idx << 1 | 1].val += tree[idx].lazy * (tree[idx << 1 | 1].r - tree[idx << 1 | 1].l + 1);
            tree[idx << 1 | 1].lazy += tree[idx].lazy;
            tree[idx].lazy = 0;
        }
    }

    inline void Build (int idx, int l, int r) {
        tree[idx].l = l, tree[idx].r = r;
        if (l == r) {
            tree[idx].val = a[l];
            return;
        }
        int mid = (l + r) >> 1;
        Build(idx << 1, l, mid);
        Build(idx << 1 | 1, mid + 1, r);
        Push_Up(idx);
    }

    inline void Update (int idx, int l, int r, ull val) {
        Push_Down(idx);
        if (tree[idx].l > r || tree[idx].r < l) return;
        if (tree[idx].l >= l && tree[idx].r <= r) {
            tree[idx].val += val * (tree[idx].r - tree[idx].l + 1);
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
        return Query(idx << 1, l, r) + Query(idx << 1 | 1, l, r);
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
	cin >> M >> N >> Q;
	for (int i=1; i<=N; i++) cin >> a[i];
	tree.Build(1, 1, N);
	while (Q--) {
		cin >> op;
		if (op == 1) {
			cin >> l >> r >> x;
			tree.Update(1, l, r, x);
		}
		else {
			cin >> l >> r;
			cout << (tree.Query(1, l, r) % M) << "\n";
		}
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