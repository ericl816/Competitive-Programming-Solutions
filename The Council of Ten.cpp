#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define ull unsigned long long
#define MAXN 1010
#define MOD 1000000007
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
#define allof(x) x.begin(), x.end()
#define DEBUG 1
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

int N, M;
int DP[MAXN][MAXN];
string word, encrypted, decoded;
vector<string> v;

inline void EditDist (string s1, string s2) {
	for (int i=0; i<=s1.size(); i++) DP[i][0] = i;
	for (int i=0; i<=s2.size(); i++) DP[0][i] = i;
	for (int i=1; i<=s1.size(); i++) {
		for (int j=1; j<=s2.size(); j++) {
		  DP[i][j] = MAXN;
		  if (s1[i - 1] ^ s2[j - 1]) {
		      DP[i][j] = min(DP[i][j], DP[i - 1][j] + 1);
		      DP[i][j] = min(DP[i][j], DP[i][j - 1] + 1);
		      DP[i][j] = min(DP[i][j], DP[i - 1][j - 1] + 1);
		  }
		  else DP[i][j] = DP[i - 1][j - 1];
		}
	}
}

int main (int argc, char const *argv[]) {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for (int i=0; i<N; i++) {
		cin >> word;
		v.pb(word);
	}
	while (M--) {
		cin >> encrypted;
		int minn = INF;
		for (auto i : v) {
			EditDist(i, encrypted);
			int ans = DP[i.size()][encrypted.size()];
			if (ans < minn) {
				minn = ans;
				decoded = i;
			}
		}
		cout << decoded << " ";
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