#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define ull unsigned long long
#define MAXM 200010
#define MAXN 100010
#define MOD 1000000007
#define INF 9223372036854775807LL
#define min(a, b) (a) < (b) ? (a) : (b)
#define max(a, b) (a) < (b) ? (b) : (a)
#define vi vector<int>
#define vll vector<ll>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define mii map<int, int>
#define umii unordered_map<int, int>
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

struct Community {
	int idx, x, y;
	bool flag;

	inline bool operator < (const Community &a) const {
		if (x == a.x) return flag > a.flag;
		return x < a.x;
	}

	inline bool operator > (const Community &a) const {
		if (x == a.x) return flag > a.flag;
		return x > a.x;
	}
};

struct Node {
	int l, r;
	ll minlazy, maxlazy, minn, maxx;
};

struct Seg {
private:
	int N;
	vector<Node> tree;

public:
	Seg (int N) : N(N), tree(N << 2) { }

	inline void Push_Down (bool type, int idx) {
		if (type) {
			if (tree[idx].l ^ tree[idx].r && tree[idx].minlazy) {
				tree[idx << 1].minlazy += tree[idx].minlazy;
				tree[idx << 1 | 1].minlazy += tree[idx].minlazy;
				tree[idx].minn += tree[idx].minlazy;
				tree[idx].minlazy = 0;
			}
		}
		else {
			if (tree[idx].l ^ tree[idx].r && tree[idx].maxlazy) {
				tree[idx << 1].maxlazy += tree[idx].maxlazy;
				tree[idx << 1 | 1].maxlazy += tree[idx].maxlazy;
				tree[idx].maxx += tree[idx].maxlazy;
				tree[idx].maxlazy = 0;
			}
		}
	}

	inline void Push_Up (bool type, int idx) {
		if (type) {
			tree[idx].minn = min(tree[idx << 1].minn, tree[idx << 1 | 1].minn);
		}
		else {
			tree[idx].maxx = max(tree[idx << 1].maxx, tree[idx << 1 | 1].maxx);
		}
	}

	inline void Build (int idx, int l, int r) {
		tree[idx].l = l, tree[idx].r = r;
		if (l == r) {
			tree[idx].minn = INF;
			tree[idx].maxx = -INF;
			return;
		}
		int mid = (l + r) >> 1;
		Build(idx << 1, l, mid);
		Build(idx << 1 | 1, mid + 1, r);
	}

	inline void Point_Update (bool type, int idx, int pos, int val) {
		Push_Down(type, idx);
		int l = tree[idx].l, r = tree[idx].r;
		if (pos < l || pos > r) return;
		if (pos == l && pos == r) {
			if (type) {
				tree[idx].minn = val;
				return;
			}
			else {
				tree[idx].maxx = val;
				return;
			}
		}
		Point_Update(type, idx << 1, pos, val);
		Point_Update(type, idx << 1 | 1, pos, val);
		Push_Up(type, idx);
	}

	inline void Range_Update (bool type, int idx, int l, int r, int val) {
		Push_Down(type, idx);
		if (tree[idx].r < l || tree[idx].l > r) return;
		if (tree[idx].l >= l && tree[idx].r <= r) {
			if (type) {
				tree[idx].minlazy = val;
				Push_Down(type, idx);
				return;
			}
			else {
				tree[idx].maxlazy = val;
				Push_Down(type, idx);
				return;
			}
		}
		Range_Update(type, idx << 1, l, r, val);
		Range_Update(type, idx << 1 | 1, l, r, val);
		Push_Up(type, idx);
	}

	inline ll Query (bool type, int idx, int l, int r) {
		Push_Down(type, idx);
		if (type) {
			if (tree[idx].r < l || tree[idx].l > r) return INF;
			if (tree[idx].l >= l && tree[idx].r <= r) return tree[idx].minn;
		}
		else {
			if (tree[idx].r < l || tree[idx].l > r) return -INF;
			if (tree[idx].l >= l && tree[idx].r <= r) return tree[idx].maxx;
		}
		return type ? min(Query(type, idx << 1, l, r), Query(type, idx << 1 | 1, l, r)) : max(Query(type, idx << 1, l, r), Query(type, idx << 1 | 1, l, r));
	}

};

int N, M, ind;
ll ans;
Community loc[MAXN];
ll minn[MAXN];
set<int> s;
umii comp;
Seg tree(MAXM);

inline void Line_Sweep () {
	int prev = loc[0].x;
	for (int i=0; i<ind; i++) {
		int pt = comp[loc[i].y];
		int dist = abs(loc[i].x - prev);
		tree.Range_Update(1, 1, 1, comp.size(), dist);
		tree.Range_Update(0, 1, 1, comp.size(), -dist);
		if (loc[i].flag) {
			ll half1 = tree.Query(0, 1, 1, pt), half2 = tree.Query(1, 1, pt + 1, comp.size());
			minn[loc[i].idx] = min(minn[loc[i].idx], min(loc[i].y - half1, half2 - loc[i].y));
		}
		else {
			tree.Point_Update(1, 1, pt, loc[i].y);
			tree.Point_Update(0, 1, pt, loc[i].y);
		}
		prev = loc[i].x;
	}
}

int main (int argc, char const *argv[]) {
	#ifdef NOT_DMOJ
	freopen("DATA.in", "r", stdin);
	freopen("DATA.out", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	memset(minn, INF, sizeof(minn));
	cin >> N;
	for (int i=0, x, y; i<N; i++) {
		cin >> x >> y;
		loc[ind++] = (Community) {i, x, y, 1};
		s.insert(y);
	}
	cin >> M;
	for (int i=0, x, y; i<M; i++) {
		cin >> x >> y;
		loc[ind++] = (Community) {-1, x, y, 0};
		s.insert(y);
	}
	int val = 0;
	for (auto i : s) comp[i] = ++val;
	tree.Build(1, 1, comp.size());
	sort(loc, loc + ind);
	Line_Sweep();
	// for (int i=0; i<N; i++) D("%d ", minn[i]);

	tree.Build(1, 1, comp.size());
	sort(loc, loc + ind, greater<Community>());
	Line_Sweep();
	// D("\n");
	// for (int i=0; i<N; i++) D("%d ", minn[i]);

	for (int i=0; i<N; i++) ans += minn[i];
	cout << ans << "\n";
	return 0;
}

/*
3
1 1
2 2
3 1
2
0 0
4 0

Ans: 8
*/

/* 
 Look for:
 * the exact constraints (multiple sets are too slow for n=10^6 :( ) 
 * special cases (n=1?)
 * overflow (ll vs int?)
 * array bounds
 * number of test cases (T = 10)
 * resetting containers, variables, etc
 */