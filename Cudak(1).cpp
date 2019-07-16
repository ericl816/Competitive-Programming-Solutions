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
ll A, B, ans = -1LL;
ll pows[MAXM];
ll DP[MAXM][MAXN];

inline ll DFS (int digits, ll pre, int sum) {
	if (sum < 0) return 0LL;
	ll minn = pre, maxx = pre + pows[digits] - 1;
	if (minn > B || maxx < A) return 0LL;
	if (digits == 0) {
		if (sum > 0) return 0LL;
		if (!~ans) ans = minn;
		return 1LL;
	}
	bool flag = minn >= A && maxx <= B;
	ll &res = DP[digits][sum];
	if (flag && ~res) return res;
	ll pos = 0LL;
	for (int i=0; i<=9; i++) {
		pos += DFS(digits - 1, pre + i * pows[digits - 1], sum - i);
	}
	if (flag) res = pos;
	return pos;
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
	pows[0] = 1LL;
	for (int i=1; i<=MAXM; i++) pows[i] = pows[i - 1] * 10LL;
	cin >> A >> B >> S;
	cout << DFS(MAXM, 0LL, S) << "\n";
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