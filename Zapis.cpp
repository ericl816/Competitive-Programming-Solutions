#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXN 210
#define MOD 100000
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

int N;
char s[MAXN];
ll DP[MAXN][MAXN];
char *seq1 = new char[3] {'(', '{', '['};
char *seq2 = new char[3] {')', '}', ']'};
bool flag;

inline ll Solve (int a, int b) {
	if (a > b) return 1;
	ll &val = DP[a][b];
	if (~val) return val;
	ll sum = 0;
	for (int i=a + 1; i<=b; i+=2) {
		for (int j=0; j<3; j++) {
			if ((s[a] == seq1[j] || s[a] == '?') && (s[i] == seq2[j] || s[i] == '?')) {
				sum += (Solve(a + 1, i - 1) * Solve(i + 1, b));
				if (sum > MOD) flag = 1;
				sum %= MOD;
			}
		}
	}
	return val = (sum % MOD + MOD) % MOD;
}

int main () {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	scanf("%d %s", &N, s);
	memset(DP, -1, sizeof(DP));
	ll ans = Solve(0, N - 1);
	if (flag) printf("%05lld\n", ans); // Print ONLY last 5 digits
	else printf("%lld\n", ans);
	return 0;
}

/* 
 * Look for:
 * the exact constraints (multiple sets are too slow for n=10^6 :( ) 
 * special cases (n=1?)
 * overflow (ll vs int?)
 * array bounds
 */