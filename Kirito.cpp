#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXN 2010
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

int N, M, Q, x, y, idx, val;
int prefix[MAXN];
string monsters[MAXN];

struct Seg {
private:
	int tree[MAXN << 2];

public:
	void Push_Up (int idx) {
		tree[idx] = min(tree[idx << 1], tree[idx << 1 | 1]);
	}

	void Build (int idx, int l, int r) {
		if (l == r) {
			tree[idx] = prefix[l];
			return;
		}
		int mid = (l + r) >> 1;
		Build(idx << 1, l, mid);
		Build(idx << 1 | 1, mid + 1, r);
		Push_Up(idx);
	}

	void Update (int idx, int l, int r, int pos) {
		if (pos == l && pos == r) {
			tree[idx] = prefix[pos];
			return;
		}
		int mid = (l + r) >> 1;
		if (pos <= mid) Update(idx << 1, l, mid, pos);
		else Update(idx << 1 | 1, mid + 1, r, pos);
		Push_Up(idx);
	}

	int Query (int idx, int l, int r, int l1, int r1) {
		if (l == l1 && r == r1) return tree[idx];
		int mid = (l + r) >> 1;
		if (r1 <= mid) return Query(idx << 1, l, mid, l1, r1);
		else if (l1 > mid) return Query(idx << 1 | 1, mid + 1, r, l1, r1);
		else return min(Query(idx << 1, l, mid, l1, mid), Query(idx << 1 | 1, mid + 1, r, mid + 1, r1));
	}

	// Check for out of bounds
	inline bool Check (int pos) {
		return pos > 1 && pos <= N;
	}

	void Update (int pos) {
		if (Check(pos)) {
			// Update prefix (LCP) array
			idx = 0;
			for (idx; idx<M; idx++) {
				if (monsters[pos][idx] != monsters[pos - 1][idx]) break;
			}
			prefix[pos] = idx;
			Update(1, 1, N, pos);
	 	}
	}
};

Seg tree;

int main () {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for (int i=1; i<=N; i++) cin >> monsters[i];
	for (int i=2; i<=N; i++) {
		idx = 0;
		for (idx; idx<M; idx++) {
			if (monsters[i][idx] != monsters[i - 1][idx]) break; // The restriction is not satisfied
		}
		prefix[i] = idx;
	}
	tree.Build(1, 1, N);
	cin >> Q;
	for (int i=0; i<Q; i++) {
		cin >> x >> y;
		val = y - x + 1; // Get number of elements in range
		if (x == y) cout << M * val << endl;
		else {
			cout << tree.Query(1, 1, N, x + 1, y) * val << endl;
			swap(monsters[x], monsters[y]); // Monsters will then switch places
			tree.Update(x);
			tree.Update(x + 1);
			tree.Update(y);
			tree.Update(y + 1);
		}
	}
	return 0;
}