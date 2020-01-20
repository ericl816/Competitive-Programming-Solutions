#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define ull unsigned long long
#define MAXN 54
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

int T = 52, score1, score2;
string s[MAXN];
int player[MAXN];

inline bool High (string s) {
	return s == "jack" || s == "queen" || s == "king" || s == "ace";
}

inline bool Check (int x, int pos) {
	for (int i=1; i<=pos; i++) {
		if (High(s[x + i])) return 0;
	}
	return 1;
}

int main (int argc, char const *argv[]) {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	for (int i=0; i<T; i++) cin >> s[i];
	for (int i=0; i<T; i++) {
		int score = 0;
		if (s[i] == "jack") score = 1;
		else if (s[i] == "queen") score = 2;
		else if (s[i] == "king") score = 3;
		else if (s[i] == "ace") score = 4;
		int id = i & 1;
		if (score && i + score < 52 && Check(i, score)) {
			cout << "Player " << (!id ? "A " : "B ") << "scores " << score << " point(s).\n";
			player[id] += score;
		}
	}
	cout << "Player A: " << player[0] << " point(s).\nPlayer B: " << player[1] << " point(s).\n";
	return 0;
}

/* 
 * Look for:
 * the exact constraints (multiple sets are too slow for n=10^6 :( ) 
 * special cases (n=1?)
 * overflow (ll vs int?)
 * array bounds
 */