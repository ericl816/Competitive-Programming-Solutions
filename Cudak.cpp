#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define ull unsigned long long
#define MAXM 17
#define MAXN 140
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

int S;
ll A, B, minn;
int digit[MAXM];
ll DP[MAXM][MAXN];

/* 
 * @param limit = whether current digits range is restricted or not
 * If it isn't, then range will span from 0 to 9 (inclusive)
 * If it is, then range will span from 0 to digit[ind] (inclusive)
 */
inline ll DFS (int ind, int sum, bool limit) {
	if (ind <= 0) return sum == S;
	ll &res = DP[ind][sum];
	if (!limit && ~res) return res;
	int val = limit ? digit[ind] : 9;
	ll pos = 0LL;
	for (int i=0; i<=val; i++) {
		pos += DFS(ind - 1, sum + i, limit && i == digit[ind]);
	}
	if (!limit) res = pos;
	return pos;
}

inline ll Query (ll k) {
    ll ans = 0;
    int ind = 0;
    while (k) {
        digit[++ind] = k % 10;
        k /= 10;
    }
    ans = DFS(ind, 0, 1);
    return ans;
}

int main (int argc, char const *argv[]) {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	memset(DP, -1, sizeof(DP));
	cin >> A >> B >> S;
	cout << Query(B) - Query(A - 1) << "\n";
	ll lo = A, hi = B;
	while (lo <= hi) {
		ll mid = (lo + hi) >> 1;
		if (Query(mid) - Query(A - 1) > 0) {
			minn = mid;
			hi = mid - 1;
		}
		else lo = mid + 1;
	}
	cout << minn << "\n";
	return 0;
}

/* 
 * Look for:
 * the exact constraints (multiple sets are too slow for n=10^6 :( ) 
 * special cases (n=1?)
 * overflow (ll vs int?)
 * array bounds
 */