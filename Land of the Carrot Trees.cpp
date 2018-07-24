#include <bits/stdc++.h>
#define ll long long
#define MAXN 5010
#define min(a, b) (a) < (b) ? (a) : (b)
#define max(a, b) (a) < (b) ? (b) : (a)
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
using namespace std;

// The simplest solution is to simply use a LCT (linked-cut-tree)
// Must implement this data structure everyday to grind it into muscle memory

int N, Q, x, y, z;
char op;

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
			bool b = n->p->p->ch[0] = n->p;
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
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> Q;
	for (int i=0; i<=N; i++) lct[i] = new node();
	for (int i=0; i<N - 1; i++) {
		int a, b, c;
		cin >> a >> b >> c;
	}
	for (int i=0; i<Q; i++) {
		cin >> op;
		if (op == 'A') { // Build a new road between cities x and y
			cin >> x >> y >> z;
		}
		else if (op == 'R') { // Cut the road between x and y
			cin >> x >> y;
		}
		else if (op == 'Q') { // Get the XOR of all roads between cities x and y
			cin >> x >> y;
		}
	}

	return 0;
}