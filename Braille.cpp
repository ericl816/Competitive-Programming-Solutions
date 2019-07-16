#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define ull unsigned long long
#define MAXM 1010
#define MAXN 5010
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define min(a, b) (a) < (b) ? (a) : (b)
#define max(a, b) (a) < (b) ? (b) : (a)
#define vi vector<int>
#define vll vector<ll>
#define pb push_back
#define pii pair<int, int>
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

string s;
map<char, string> mp;

inline void Preprocess () {
	mp['A'] = "o.....";
	mp['B'] = "o.o...";
	mp['C'] = "oo....";
	mp['D'] = "oo.o..";
	mp['E'] = "o..o..";
	mp['F'] = "ooo...";
	mp['G'] = "oooo..";
	mp['H'] = "o.oo..";
	mp['I'] = ".oo...";
	mp['J'] = ".ooo..";
	mp['K'] = "o...o.";
	mp['L'] = "o.o.o.";
	mp['M'] = "oo..o.";
	mp['N'] = "oo.oo.";
	mp['O'] = "o..oo.";
	mp['P'] = "ooo.o.";
	mp['Q'] = "ooooo.";
	mp['R'] = "o.ooo.";
	mp['S'] = ".oo.o.";
	mp['T'] = ".oooo.";
	mp['U'] = "o...oo";
	mp['V'] = "o.o.oo";
	mp['W'] = ".ooo.o";
	mp['X'] = "oo..oo";
	mp['Y'] = "oo.ooo";
	mp['Z'] = "o..ooo";
	mp[' '] = "......";
}

int main (int argc, char const *argv[]) {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	Preprocess();
	getline(cin, s);
	string ans = "";
	for (auto i : s) {
		ans += mp[i][0];
		ans += mp[i][1];
	}
	ans += "\n";
	for (auto i : s) {
		ans += mp[i][2];
		ans += mp[i][3];
	}
	ans += "\n";
	for (auto i : s) {
		ans += mp[i][4];
		ans += mp[i][5];
	}
	cout << ans << "\n";
	return 0;
}

/*
o.o.o..oo.o.o....o.o..o....oo.o.o...o.ooo..ooo
o.oo..o.o.o..o..o.o.......oo.oo.o......o.ooo.o
..o.....o.o.......o........o..o.o...o.o.o..oo.
*/

/* 
 Look for:
 * the exact constraints (multiple sets are too slow for n=10^6 :( ) 
 * special cases (n=1?)
 * overflow (ll vs int?)
 * array bounds
 * number of test cases (T = 10)
 * resetting containers, variables, etc
 */