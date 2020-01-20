#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define ull unsigned long long
#define MAXN 110
#define MOD 1000000007
#define INF 0x3f3f3f3f
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

int N, K, ans;
string s;
int DP[MAXN][MAXN][MAXN][2];

inline int Solve (int l, int r, int cnt, bool take) {
	if (l > r) return cnt < K ? INF : 1;
	int &res = DP[l][r][cnt][take];
	D("%d\n", res);
	if (~res) return res;
	int val = INF;
	bool flag = s[l] == 'G';
	if (flag == take) val = Solve(l + 1, r, cnt + 1, take);
	for (int i=l; i<r; i++) val = min(val, min(Solve(l, i, 0, 0), Solve(l, i, 0, 1)) + Solve(i + 1, r, cnt, take));
	D("%d\n", val);
	return res = val;
}

int main (int argc, char const *argv[]) {
	#ifdef NOT_DMOJ
	freopen("DATA.in", "r", stdin);
	freopen("DATA.out", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> K >> s;
	memset(DP, -1, sizeof(DP));
	ans = min(Solve(0, N - 1, 0, 0), Solve(0, N - 1, 0, 1));
	cout << (ans == INF ? -1 : ans) << "\n";
	return 0;
}

/* 
 Look for:
 * the exact constraints (multiple sets are too slow for n=10^6 :( ) 
 * special cases (n=1?)
 * overflow (ll vs int?)
 * array bounds
 * number of test cases (T = 10)
 * resetting containers, variables, etc
 */