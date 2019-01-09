#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXN 1000010
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
#define DEBUG 1
#ifdef DEBUG
    #define D(x...) printf(x)
#else
    #define D(x...)
#endif
using namespace std;

int N, Q, op, l, r, a;

struct Node {
    int l, r;
    ll val, lazy, lazy_upd;
};

struct Seg {
private:
    int N;
    vector<Node> tree;

public:
    Seg (int N) : N(N), tree(N << 2) { }

    inline void Push_Up (int idx) {
        tree[idx].val = tree[idx << 1].val + tree[idx << 1 | 1].val;
    }

    inline void Push_Down (int idx) {
        if (tree[idx].lazy && tree[idx].l ^ tree[idx].r) {
            int l = tree[idx].l, r = tree[idx].r, mid = (l + r) >> 1;
            tree[idx].val += tree[idx].lazy * ((r - l + 2) * (r - l + 1) >> 1);
            tree[idx].val += tree[idx].lazy_upd;
            tree[idx << 1].lazy += tree[idx].lazy;
            tree[idx << 1].lazy_upd += tree[idx].lazy_upd;
            tree[idx << 1 | 1].lazy += tree[idx].lazy;
            tree[idx << 1 | 1].lazy_upd += tree[idx].lazy_upd + tree[idx].lazy * (mid - l + 1);
            tree[idx].lazy = tree[idx].lazy_upd = 0LL;
        }
    }

    inline void Build (int idx, int l, int r) {
        tree[idx].l = l, tree[idx].r = r;
        if (l == r) {
            tree[idx].val = 0LL;
            return;
        }
        int mid = (l + r) >> 1;
        Build(idx << 1, l, mid);
        Build(idx << 1 | 1, mid + 1, r);
        Push_Up(idx);
    }

    inline void Update (int idx, int l, int r, int val, int upd) {
        Push_Down(idx);
        if (tree[idx].l > r || tree[idx].r < l) return;
        int mid = (tree[idx].l + tree[idx].r) >> 1;
        if (tree[idx].l >= l && tree[idx].r <= r) {
            tree[idx].lazy += val;
            tree[idx].lazy_upd += upd;
            tree[idx].val += val * ((tree[idx].r - tree[idx].l + 2) * (tree[idx].r - tree[idx].l + 1) >> 1);
            tree[idx].val += upd;
            return;
        }
        if (r <= mid) Update(idx << 1, l, r, val, upd);
        else if (l > mid) Update(idx << 1 | 1, l, r, val, upd + max(0, (mid - l + 1) * val));
        else {
            Update(idx << 1, l, mid, val, upd);
            Update(idx << 1 | 1, mid + 1, r, val, upd + max(0, (mid - l + 1) * val));
        }
        Push_Up(idx);
    }

    inline ll Query (int idx, int l, int r) {
        Push_Down(idx);
        if (tree[idx].l > r || tree[idx].r < l) return 0;
        if (tree[idx].l >= l && tree[idx].r <= r) return tree[idx].val;
        int mid = (tree[idx].l + tree[idx].r) >> 1;
        if (r <= mid) return Query(idx << 1, l, r);
        else if (l > mid) return Query(idx << 1 | 1, l, r);
        else return Query(idx << 1, l, mid) + Query(idx << 1 | 1, mid + 1, r);
    }
} tree(MAXN);

int main () {
    #ifdef NOT_DMOJ
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif // NOT_DMOJ
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> Q;
    tree.Build(1, 1, N);
    while (Q--) {
    	cin >> op >> l >> r;
    	if (op == 2) cout << tree.Query(1, l, r) << "\n";
    	else {
    		cin >> a;
            tree.Update(1, l, r, a, 0);
    	}
    }
    return 0;
}

/*
3 4
1 2 3 2
2 1 1
2 2 2
2 3 3
Ans:
0
2
4

3 4
1 2 3 3
2 1 2
2 2 3
2 1 3
Ans:
3
9
9
*/

/* 
 * Look for:
 * the exact constraints (multiple sets are too slow for n=10^6 :( ) 
 * special cases (n=1?)
 * overflow (ll vs int?)
 * array bounds
 */