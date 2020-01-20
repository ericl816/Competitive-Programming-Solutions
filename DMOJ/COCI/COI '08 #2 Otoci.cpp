#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC optimize "omit-frame-pointer"
#pragma GCC optimize "prefetch-loop-arrays"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,aes,sse4a,sse4.1,sse4.2,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define ull unsigned long long
#define MAXN 30010
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) < (b) ? (b) : (a))
#define vi vector<int>
#define vll vector<ll>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define mii map<int, int>
#define umii unordered_map<int, int>w
#define allof(x) x.begin(), x.end()
#define DEBUG 1
// #define NOT_DMOJ 0
#ifdef DEBUG
	#define D(x...) printf(x)
#else
	#define D(x...)
#endif
using namespace std;

inline int GCD (int a, int b) { return b == 0 ? a : GCD(b, a % b); }
inline int LCM (int a, int b) { return a * b / GCD(a, b); }
inline ll PowMod (ll a, ll b, ll mod) { ll val = 1; while (b) { if (b & 1) val = (val * a) % mod; a = (a * a) % mod; b >>= 1; } return val; }

struct node {
    int val, sum;
    bool rev;
    node *p, *ch[2];
    node (int i) : val(i), sum(i), rev(0), p(0), ch{0} { }
};

inline bool par (node *n) {
    return n->p && (n->p->ch[0] == n || n->p->ch[1] == n);
}

inline int sum (node *n) {
    return n ? n->sum : 0;
}

inline void push (node *n) {
    if (!n) return;
    if (n->rev) {
    	swap(n->ch[0], n->ch[1]);
        if (n->ch[0]) n->ch[0]->rev ^= 1;
        if (n->ch[1]) n->ch[1]->rev ^= 1;
        n->rev = 0;
    }
}

inline void update (node *n) {
    if (!n) return;
    n->sum = sum(n->ch[0]) + sum(n->ch[1]) + n->val;
}

inline void rotate (node *n, bool b) {
    node *p = n->p;
	p->ch[b ^ 1] = n->ch[b];
	if (n->ch[b]) n->ch[b]->p = p;
	n->p = p->p;
	if (p->p) {
		if (p->p->ch[0] == p) n->p->ch[0] = n;
		else if (p->p->ch[1] == p) n->p->ch[1] = n;
	}
	p->p = n;
	update(n->ch[b] = p);
}

inline void splay (node *n) {
    while (par(n)) {
        if (par(n->p)) push(n->p->p);
        push(n->p), push(n);
        if (par(n->p)) {
            bool b = n->p == n->p->p->ch[0];
            if (n->p->ch[b] == n) {
            	rotate(n, b ^ 1);
            	rotate(n, b);
            }
            else {
            	rotate(n->p, b);
            	rotate(n, b);
            }
        }
        else rotate(n, n->p->ch[0] == n);
    }
    push(n);
    update(n);
}

inline node* access (node *u) {
    node *lst = 0;
    for (node *v=u; v; v=v->p) {
        splay(v);
        v->ch[0] = lst;
        lst = v;
    }
    splay(u);
    return lst;
}

inline void make_root (node *n) {
    access(n);
    n->rev ^= 1;
}

inline bool connected (node *u, node *v) {
    if (u==v) return 1;
    access(u);
    access(v);
    return u->p;
}

inline void link (node *u, node *v) {
    make_root(u);
    u->p = v;
}

inline int query (node *u, node *v) {
    make_root(u);
    access(v);
    return v->sum;
}

int N, Q, A, B, X, penguins;
string op;
node *lct[MAXN];

int main (int argc, char const *argv[]) {
	#ifdef NOT_DMOJ
	freopen("DATA.in", "r", stdin);
	freopen("DATA.out", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for (int i=1; i<=N; i++) {
		cin >> penguins;
		lct[i] = new node(penguins);
	}
	cin >> Q;
	while (Q--) {
		cin >> op;
		if (op == "bridge") {
			cin >> A >> B;
			if (connected(lct[A], lct[B])) {
				cout << "no\n" << flush;
			}
			else {
				link(lct[A], lct[B]);
				cout << "yes\n" << flush;
			}
		}
		else if (op == "penguins") {
			cin >> A >> X;
			splay(lct[A]);
			lct[A]->val = X;
			update(lct[A]);
		}
		else if (op == "excursion") {
			cin >> A >> B;
			if (!connected(lct[A], lct[B])) cout << "impossible\n" << flush;
			else cout << query(lct[A], lct[B]) << "\n" << flush;
		}
	}
	return 0;
}

/* 
 Look for:
 * the exact constraints (multiple sets are too slow for n=10^6 :( ) 
 * special cases (n=1?)
 * overflow (ll vs int?)
 * array bounds
 * number of test cases (T = 10)
 * resetting containers, variables, etc
 */