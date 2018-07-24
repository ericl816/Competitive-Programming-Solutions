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

// Using solution to Dynamic LCA as code for template

/*
Problem Statement:

A forest of rooted trees initially consists of N (1 ≤ N ≤ 100,000) single-vertex trees. The vertices are numbered from 1 to N.

You must process the following queries, where (1 ≤ A, B ≤ N):

link A B : add an edge from vertex A to B, making A a child of B, where initially A is a root vertex, A and B are in different trees.
cut A : remove edge from A to its parent, where initially A is a non-root vertex.
lca A B : print the lowest common ancestor of A and B, where A and B are in the same tree.
*/

int N, M, A, B;
string op;

struct node {
	int sz;
	node *p, *ch[2];
	node (int i) : sz(i), p(0), ch{0} { }
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
	n->ch[b] = p;
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

inline node *lca (node *u, node *v) {
	access(u);
	return access(v);
}

inline void cut (node *n) {
	access(n);
	if (!n->ch[0]) return;
	n->ch[0]->p = 0;
	n->ch[0] = 0;
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
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for (int i=1; i<=N; i++) lct[i] = new node(i);
	while (M--) {
		cin >> op;
		if (op == "link") {
			cin >> A >> B;
			link(lct[A], lct[B]);
		}
		else if (op == "cut") {
			cin >> A;
			cut(lct[A]);
		}
		else if (op == "lca") {
			cin >> A >> B;
			cout << size(lca(lct[A], lct[B])) << "\n";
		}
	}
	return 0;
}