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

int N, M;
vi mst;

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
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	scan(N); scan(M);
	for (int i=1; i<MAXN; i++) lct[i] = new node();
	for (int i=1, a, b; i<=M; i++) {
		scan(a); scan(b);
		node *u = access(lct[a]);
		node *v = access(lct[b]);
		if (u == v) continue;
		mst.pb(i);
		link(u, v);
	}
	if (mst.size() ^ N - 1) {
		cout << "Disconnected Graph" << "\n";
		return 0;
	}
	for (auto i : mst) cout << i << "\n";
	return 0;
}