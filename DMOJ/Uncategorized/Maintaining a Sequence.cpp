#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f3f3f3f
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
#ifdef DEBUG
    #define D(x...) printf(x)
#else
    #define D(x...)
#endif
using namespace std;

struct Node {
    int val, p, sz, lazy;
    Node *l, *r;
    ll psum, ssum, tsum, bsum;
    bool rev, prop;
    Node (int i) : val(i), p(rand()), sz(1), lazy(0), psum(i), ssum(i), tsum(i), bsum(i), rev(0), prop(0), l(0), r(0) { }
} *root;

inline int sz (Node *n) {
    return n ? n-> sz : 0LL;
}

inline ll psum (Node *n) {
    return n ? n->psum : 0LL;
}

inline ll ssum (Node *n) {
    return n ? n->ssum : 0LL;
}

inline ll tsum (Node *n) {
    return n ? n->tsum : 0LL;
}

inline ll bsum (Node *n) {
    return n ? n->bsum : -INF;
}

inline void push (Node *n) {
    if (!n) return;
    if (n->prop) {
        n->val = n->lazy;
        n->psum = n->ssum = n->bsum = 1LL * (n->lazy <= 0 ? 1LL : n->sz) * n->lazy;
        n->tsum = 1LL * n->sz * n->lazy;
        if (n->l) {
            n->l->lazy = n->lazy;
            n->l->prop = 1;
        }
        if (n->r) {
            n->r->lazy = n->lazy;
            n->r->prop = 1;
        }
        n->prop = 0;
    }
    if (n->rev) {
        swap(n->l, n->r);
        swap(n->psum, n->ssum);
        if (n->l) n->l->rev ^= 1;
        if (n->r) n->r->rev ^= 1;
        n->rev = 0;
    }
}

inline void update (Node *n) {
    if (!n) return;
    ll lbsum = n->val;
    n->bsum = n->val;
    n->tsum = n->val;
    push(n->l);
    push(n->r);
    if (n->l) {
        n->psum = max(psum(n->l), tsum(n->l) + n->val + (max(0LL, psum(n->r))));
        n->bsum = max(n->bsum, max(bsum(n->l), ssum(n->l) + n->val));
        n->tsum += tsum(n->l);
        lbsum += ssum(n->l);
    }
    else n->psum = n->val + (max(0LL, psum(n->r)));
    if (n->r) {
        n->ssum = max(ssum(n->r), tsum(n->r) + n->val + (max(0LL, ssum(n->l))));
        n->bsum = max(n->bsum, max(bsum(n->r), max(lbsum + psum(n->r), n->val + psum(n->r))));
        n->tsum += tsum(n->r);
    }
    else n->ssum = n->val + (max(0LL, ssum(n->l)));
    n->sz = sz(n->l) + 1 + sz(n->r);
}

inline void merge (Node *&n, Node *l, Node *r) {
    push(l);
    push(r);
    if (!l || !r) n = l ? l : r;
    else if (l->p > r->p) {
        merge(l->r, l->r, r);
        n = l;
    }
    else {
        merge(r->l, l, r->l);
        n = r;
    }
    update(n);
}

inline void split (Node *n, Node *&l, Node *&r, int key) {
    push(n);
    if (!n) l = r = 0;
    else if (sz(n->l) < key) {
        split(n->r, n->r, r, key - sz(n->l) - 1);
        l = n;
    }
    else {
        split(n->l, l, n->l, key);
        r = n;
    }
    update(n);
}

int N, M, a, b, c, d;
string op;

int main (int argc, char const *argv[]) {
    #ifdef NOT_DMOJ
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif // NOT_DMOJ
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for (int i=0; i<N; i++) {
        cin >> a;
        merge(root, root, new Node(a));
    }
    while (M--) {
        cin >> op;
        if (op == "INSERT") {
            cin >> a >> b;
            Node *tmp = 0, *l = 0, *m = 0, *r = 0;
            while (b--) {
                cin >> d;
                merge(tmp, tmp, new Node(d));
            }
            split(root, l, r, a);
            merge(m, l, tmp);
            merge(root, m, r);
        }
        else if (op == "DELETE") {
            cin >> a >> b;
            Node *tmp = 0, *l = 0, *m = 0, *r = 0;
            split(root, l, tmp, a - 1);
            split(tmp, m, r, b);
            merge(root, l, r);
        }
        else if (op == "MAKE-SAME") {
            cin >> a >> b >> c;
            Node *tmp = 0, *l = 0, *m = 0, *r = 0;
            split(root, l, tmp, a - 1);
            split(tmp, m, r, b);
            if (m) {
                m->lazy = c;
                m->prop = 1;
            }
            merge(tmp, m, r);
            merge(root, l, tmp);
        }
        else if (op == "REVERSE") {
            cin >> a >> b;
            Node *tmp = 0, *l = 0, *m = 0, *r = 0;
            split(root, l, tmp, a - 1);
            split(tmp, m, r, b);
            if (m) m->rev ^= 1;
            merge(tmp, m, r);
            merge(root, l, tmp);
        }
        else if (op == "GET-SUM") {
            cin >> a >> b;
            Node *tmp = 0, *l = 0, *m = 0, *r = 0;
            split(root, l, tmp, a - 1);
            split(tmp, m, r, b);
            cout << tsum(m) << "\n";
            merge(tmp, m, r);
            merge(root, l, tmp);
        }
        else cout << bsum(root) << "\n";
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