#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define ull unsigned long long
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
#define println cout << "\n";
#ifdef DEBUG
    #define D(x...) printf(x)
#else
    #define D(x...)
#endif
using namespace std;

int N, M, a, x, ans;
char op;

struct Node {
    int val, p, sz;
    Node *ch[2];
    Node (int i) : val(i), p(rand()), sz(1) { ch[0] = ch[1] = NULL; }
} *root;

inline int sz (Node *n) {
    return n ? n->sz : 0;
}

inline void upd_sz (Node *n) {
    if (n) n->sz = sz(n->ch[0]) + 1 + sz(n->ch[1]);
}

inline void rotate (Node *&n, bool flag) {
    Node *tmp = n->ch[flag];
    n->ch[flag] = tmp->ch[flag ^ 1];
    tmp->ch[flag ^ 1] = n;
    upd_sz(n);
    upd_sz(tmp);
    n = tmp;
}

inline void insert (Node *&n, Node *i) {
    if (!n) n = i;
    else {
        bool flag = n->val < i->val;
        insert(n->ch[flag], i);
        if (n->ch[flag]->p > n->p) rotate(n, flag);
    }
    upd_sz(n);
}

inline void del (Node *&n, int i) {
    if (!n) return;
    if (n->val == i) {
        if (!n->ch[0] || !n->ch[1]) n = n->ch[0] ? n->ch[0] : n->ch[1];
        else {
            bool flag = n->ch[1]->p > n->ch[0]->p;
            rotate(n, flag);
            del(n->ch[flag ^ 1], i);
        }
    }
    else del(n->ch[n->val < i], i);
    upd_sz(n);
}

inline int select (Node *n, int i) {
    if (sz(n->ch[0]) + 1 == i) return n->val;
    else if (sz(n->ch[0]) + 1 < i) return select(n->ch[1], i - sz(n->ch[0]) - 1);
    else return select(n->ch[0], i);
}

inline int rnk (Node *n, int i, int s) {
    if (!n) return -1;
    if (n->val == i) {
        int tmp = rnk(n->ch[0], i, s);
        return ~tmp ? tmp : s + sz(n->ch[0]) + 1;
    }
    else if (n->val < i) return rnk(n->ch[1], i, s + 1 + sz(n->ch[0]));
    else return rnk(n->ch[0], i, s);
}

inline void display (Node *n) {
    if (!n) return;
    display(n->ch[0]);
    printf("%d ", n->val);
    display(n->ch[1]);
}

int main (int argc, char const *argv[]) {
    #ifdef NOT_DMOJ
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif // NOT_DMOJ
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    scanf("%d %d", &N, &M);
    for (int i=0, a; i<N; i++) {
        scanf("%d", &a);
        insert(root, new Node(a));
    }
    for (int i=0, x; i<M; i++) {
        scanf(" %c %d", &op, &x);
        x ^= ans;
        if (op == 'I') insert(root, new Node(x));
        else if (op == 'R') del(root, x);
        else if (op == 'S') {
            ans = select(root, x);
            printf("%d\n", ans);
        }
        else if (op == 'L') {
            ans = rnk(root, x, 0);
            printf("%d\n", ans);
        }
    }
    display(root);
    return 0;
}

/* 
 * Look for:
 * the exact constraints (multiple sets are too slow for n=10^6 :( ) 
 * special cases (n=1?)
 * overflow (ll vs int?)
 * array bounds
 */