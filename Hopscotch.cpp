#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
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
using namespace std;

int N, Q;

struct node {
	int sz;
	node *p, *ch[2];
	node () : sz(1), p(0), ch{0} { }
} *lct[MAXN];

inline bool par (node *n) {
	return n->p && (n->p->ch[0] == n || n->p->ch[1] == n);
}

inline int size (node *n) {
	return n ? n->sz : 0;
}

inline void update (node *n) {
	n->sz = size(n->ch[0]) + size(n->ch[1]) + 1;
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
		if (par(n->p)) {
			bool b = n->p->p->ch[0] == n->p;
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
	update(n);
}

inline node *access (node *u) {
	node *lst = 0;
	for (node *v=u; v; v=v->p) {
		splay(v);
		v->ch[1] = lst;
		lst = v;
	}
	splay(u);
	return lst;
}

inline void cut (node *n) {
	access(n);
	if (!n->ch[0]) return;
	n->ch[0]->p = 0;
	n->ch[0] = 0;
	update(n);
}

inline void link (node *u, node *v) {
	access(u);
	u->p = v;
}

inline int query (node *n) {
	access(n);
	return size(n) - 1;
}

int main () {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	scan(N);
	for (int i=0; i<=N; i++) lct[i] = new node();
	for (int i=0, K; i<N; i++) {
		scan(K);
		link(lct[i], lct[min(N, K + i)]);
	}
	scan(Q);
	for (int i=0, op, x, v; i<Q; i++) {
		scan(op);
		if (op == 1) {
			scan(x);
			printf("%d\n", query(lct[x]));
		}
		else {
			scan(x); scan(v);
			cut(lct[x]);
			link(lct[x], lct[min(N, x + v)]);
		}
	}
	return 0;
}