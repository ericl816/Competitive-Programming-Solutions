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
#define vll vector<ll>
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

// Directly based off of this: https://www.spoj.com/problems/GSS4/

int N, M, x, l, r;
int a[MAXN];

struct Node {
	int l, r;
	ll maxx, sum;
};

struct Seg {
private:
	int N;
	vector<Node> tree;

public:
	Seg (int N) : N(N), tree(N << 2) { }

	inline void Push_Up (int idx) {
		tree[idx].maxx = max(tree[idx << 1].maxx, tree[idx << 1 | 1].maxx);
		tree[idx].sum = tree[idx << 1].sum + tree[idx << 1 | 1].sum;
	}

	inline void Build (int idx, int l, int r) {
		tree[idx].l = l, tree[idx].r = r;
		if (l == r) {
			tree[idx].maxx = tree[idx].sum = a[l];
			return;
		}
		int mid = (l + r) >> 1;
		Build(idx << 1, l, mid);
		Build(idx << 1 | 1, mid + 1, r);
		Push_Up(idx);
	}

	inline void Update (int idx, int l, int r) {
		if (tree[idx].maxx <= 1 || tree[idx].l > r || tree[idx].r < l) return;
		if (tree[idx].l == tree[idx].r) {
			tree[idx].maxx = tree[idx].sum = (ll) floor(sqrt(tree[idx].maxx));
			return;
		}
		Update(idx << 1, l, r);
		Update(idx << 1 | 1, l, r);
		Push_Up(idx);	
	}

	inline ll Query (int idx, int l, int r) {
		if (tree[idx].l > r || tree[idx].r < l) return 0LL;
		if (tree[idx].l >= l && tree[idx].r <= r) return tree[idx].sum;
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
	cin >> N;
	for (int i=1; i<=N; i++) cin >> a[i];
	cin >> M;
	tree.Build(1, 1, N);
	for (int i=0; i<M; i++) {
		cin >> x >> l >> r;
		if (x == 1) cout << tree.Query(1, l, r) << "\n";
		else {
			// Need to change value of ai from i=1,2,3...N to floor(sqrt(ai))
			tree.Update(1, l, r);
		}
	}
	return 0;
}

/*
4
1 100 5 5
5
1 1 2
2 1 2
1 1 2
2 2 3
1 1 4
*/

/* 
 * Look for:
 * the exact constraints (multiple sets are too slow for n=10^6 :( ) 
 * special cases (n=1?)
 * overflow (ll vs int?)
 * array bounds
 */