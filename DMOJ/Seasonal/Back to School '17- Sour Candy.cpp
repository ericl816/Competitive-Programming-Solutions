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

	inline void Update (int idx, int val) {
		for (; idx<=MAXN; idx += idx & -idx) tree[idx] += val;
	}

	inline ll Query (int idx) {
		ll sum = 0;
		for (; idx; idx -= idx & -idx) sum += tree[idx];
		return sum;
	}

	inline ll Query (int a, int b) {
		return Query(b) - Query(a - 1);
	}
};

BIT tree(MAXN);
int N;
int arr[MAXN], ord[MAXN], DP[MAXN];
mii sour;
pii orig, res;

int main () {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for (int i=1; i<=N; i++) {
		cin >> arr[i];
		sour[arr[i]] = i;
	}
	for (int i=1; i<=N; i++) {
		cin >> ord[i];
		arr[sour[ord[i]]] = i;
	}
	for (int i=1; i<=N; i++) sour[arr[i]] = i;
	orig = pii(-1, 0);
	res = pii(0, 1);
	sour[0] = 0;
	for (int i=1; i<=N; i++) {
		if (sour[i - 1] < sour[i]) res.f++;
		else {
			orig = max(orig, res);
			res = pii(1, i);
		}
	}
	orig = max(orig, res);
	cout << N - orig.f << "\n";
	for (int i=orig.s - 1; i; i--) {
		cout << "F ";
		cout << sour[i] + tree.Query(sour[i]) << "\n";
		tree.Update(1, 1);
		tree.Update(sour[i], -1);
	}
	for (int i=orig.f + orig.s; i<=N; i++) {
		cout << "B ";
		cout << sour[i] + tree.Query(sour[i]) << "\n";
		tree.Update(sour[i] + 1, -1);
		tree.Update(N + 1, 1);
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