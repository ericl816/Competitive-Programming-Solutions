#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXN 250010
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
#ifdef DEBUG
	#define D(x...) printf(x)
#else
	#define D(x...)
#endif
using namespace std;

int N, M, A, B;
int dials[10], lazy[MAXN * 5];
int tree[MAXN * 5][10];
string s;

inline void Shift (int arr[10], int idx) {
	for (int i=0; i<10; i++) dials[(i + idx) % 10] = arr[i];
	for (int i=0; i<10; i++) arr[i] = dials[i];
}

inline void Push_Down (int idx) {
	if (lazy[idx]) {
	    lazy[idx << 1] += lazy[idx];
	    lazy[idx << 1 | 1] += lazy[idx];
	    Shift(tree[idx << 1], lazy[idx]);
	    Shift(tree[idx << 1 | 1], lazy[idx]);
	    lazy[idx] = 0;
	}
}

inline void Push_Up (int idx) {
	for (int i=0; i<10; i++) tree[idx][i] = tree[idx << 1][i] + tree[idx << 1 | 1][i];
}

inline void Build (int idx, int l, int r) {
	if (l == r) {
		tree[idx][s[l] - '0']++;
		return;
	}
	int mid = (l + r) >> 1;
	Build(idx << 1, l, mid);
	Build(idx << 1 | 1, mid + 1, r);
	Push_Up(idx);
}

inline void Update (int idx, int l, int r, int l1, int r1, int val) {
	Push_Down(idx);
	if (l > r1 || r < l1) return;
	if (l >= l1 && r <= r1) {
		lazy[idx] += val;
		Shift(tree[idx], val);
		return;
	}
	int mid = (l + r) >> 1;
	if (r1 <= mid) Update(idx << 1, l, mid, l1, r1, val);
	else if (l1 > mid) Update(idx << 1 | 1, mid + 1, r, l1, r1, val);
	else {
		Update(idx << 1, l, mid, l1, mid, val);
		Update(idx << 1 | 1, mid + 1, r, mid + 1, r1, val);
	}
	Push_Up(idx);
}

inline int Query (int idx, int l, int r, int l1, int r1) {
	Push_Down(idx);
	if (l > r1 || r < l1) return 0;
	int val = 0;
	if (l >= l1 && r <= r1) {
		for (int i=0; i<10; i++) val += tree[idx][i] * i;
		return val;
	}
	int mid = (l + r) >> 1;
	if (r1 <= mid) return Query(idx << 1, l, mid, l1, r1);
	else if (l1 > mid) return Query(idx << 1 | 1, mid + 1, r, l1, r1);
	else return Query(idx << 1, l, mid, l1, mid) + Query(idx << 1 | 1, mid + 1, r, mid + 1, r1);
}

int main () {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M >> s;
	s = " " + s;
	Build(1, 1, N);
	for (int i=0; i<M; i++) {
		cin >> A >> B;
		cout << (Query(1, 1, N, A, B)) << "\n";
		Update(1, 1, N, A, B, 1);
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