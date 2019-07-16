#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define ull unsigned long long
#define MAXM 110
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

int N, M, a, b, c, d;
char ch[MAXM][MAXN];
vector<char> st[MAXN];
map<char, int> freq, maxx, occ;
char ans[MAXN];

int main (int argc, char const *argv[]) {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	char cc[4] = {'A', 'B', 'C', 'D'};
	cin >> N >> M >> a >> b >> c >> d;
	maxx['A'] = a, maxx['B'] = b, maxx['C'] = c, maxx['D'] = d;
	for (int i=0; i<M; i++) {
		for (int j=0; j<N; j++) {
			cin >> ch[i][j];
			st[j].pb(ch[i][j]);
		}
	}
	for (int i=0; i<N; i++) {
		freq.clear();
		int most = -1;
		char house = 'E';
		for (auto j : st[i]) freq[j]++;
		int T = 100;
		while (T--) {
			for (auto j : cc) {
				if (maxx[j] == 0 || occ[j] >= maxx[j]) continue;
				if (most < freq[j]) {
					most = freq[j];
					house = j;
				}
			}
			occ[house]++;
			if (occ[house] <= maxx[house]) break;
		}
		bool bad = 1;
		for (auto j : cc) {
			bad &= ((maxx[j] < occ[j]) || !maxx[j]);
		}
		if (bad) house = 'E';
		ans[i] = house;
	}
	for (int i=0; i<N; i++) cout << ans[i] << "\n";
	return 0;
}

/* 
 * Look for:
 * the exact constraints (multiple sets are too slow for n=10^6 :( ) 
 * special cases (n=1?)
 * overflow (ll vs int?)
 * array bounds
 */