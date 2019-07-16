#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define ull unsigned long long
#define MAXN 1000010
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

/*
        Given p, convert every inputted number to num-p, and test for if the subsequence 
        sums to >= 0. Use integers, no decimals needed.
        Using naive for loops, it will take O(n^2).
        
        But.
        We get prefix sum array instead. 
        To check if from ai to aj the sum is >= 0, just check if pref[j]-pref[i-1]>=0.
        Check at sj, is there anything before it that's <= sj? If there is, add 1 to the total.
        Remember to add 1 to the total if sj is already 0.
        
        Inversion: Given array a, if i<j and ai>aj, it's an inversion.
        This can be done using bit.
        For a 3 2 1 4
        bit
        3: check how many after it is in the bit. None? Inversion = 0. Add 1 to 3 in bit.
        2: check. 1 after it. Inversion = 1. Add 1 to 2 in bit.
        1: check. 2 after it. Inversion = 2. Add 1 to 1 in bit.
        4: check. None after it. Inversion = 0. Add 1 to 4 in bit.
        Sum into a total to find total inversions. 
        This takes O(logn) time.
        
        Vudu takes a similar principle. For any sj, its "inversion" is the total number
        of elements before it minus all those that are larger than it. This will give 
        the total number of elements that are <= it.
        For the bit index, use p+sj
*/

int N, P;
int a[MAXN], A[MAXN];
ll ans;
ll PSA[MAXN];

struct BIT {
private:
	int N;
	vector<ll> tree;

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
};

BIT tree(MAXN);

int main (int argc, char const *argv[]) {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for (int i=0; i<N; i++) cin >> a[i];
	cin >> P;
	a[0] -= P;
	PSA[0] = a[0];
	for (int i=1; i<N; i++) {
		a[i] += a[i - 1] - P;
		PSA[i] = a[i];
	}
	sort(PSA, PSA + N);
	for (int i=0; i<N; i++) {
		int rank = int(lower_bound(PSA, PSA + N, a[i]) - PSA);
		++rank;
		ans += tree.Query(rank);
		if (a[i] >= 0) ans++;
		tree.Update(rank, 1);
	}
	cout << ans << "\n";
	return 0;
}

/* 
 * Look for:
 * the exact constraints (multiple sets are too slow for n=10^6 :( ) 
 * special cases (n=1?)
 * overflow (ll vs int?)
 * array bounds
 */