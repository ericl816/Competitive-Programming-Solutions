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

struct BIT {
private:
	int N;
	vi tree;

public:
	BIT (int N) : N(N), tree(N + 1) { }

	void Update (int idx, int val) {
		for (; idx<=MAXN; idx += idx & -idx) tree[idx] = max(tree[idx], val);
	}

	int Query (int idx) {
		int sum = 0;
		for (; idx; idx -= idx & -idx) sum = max(sum, tree[idx]);
		return sum;
	}
};

BIT tree(MAXN);

int N, X, Y, ans = 1;
pii arr[MAXN];

inline bool Cmp (pii &a, pii &b) {
	if (a.f == b.f) return a.s > b.s;
	return a.f < b.f;
}

int main () {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for (int i=0; i<N; i++) {
		cin >> X >> Y;
		arr[i] = mp(X, Y);
	}
	sort(arr, arr + N , Cmp);
	tree.Update(arr[0].s, 1);
	for (int i=1; i<N; i++) {
		int res = tree.Query(arr[i].s - 1);
		ans = max(ans, res + 1);
		tree.Update(arr[i].s, res + 1);
	}
	cout << ans << "\n";
	return 0;
}