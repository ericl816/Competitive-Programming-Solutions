#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define ull unsigned long long
#define MAXN 100010
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

int N;
string s[MAXN];
map<string, bool> flag;
map<string, int> freq;
pair<string, int> p[MAXN];

inline bool Cmp (pair<string, int> &a, pair<string, int> &b) {
	if (a.s == b.s) {
		if (a.f != "Ritzy Bitz") return a.f.length() > b.f.length();
		else return 0;
	}
	return a.s > b.s;
}

int main (int argc, char const *argv[]) {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	cin.ignore();
	for (int i=0; i<N; i++) {
		getline(cin, s[i]);
		freq[s[i]]++;
	}
	p[0] = mp("Sashimi", freq["Sashimi"]);
	p[1] = mp("Deluxe Tuna Bitz", freq["Deluxe Tuna Bitz"]);
	p[2] = mp("Bonito Bitz", freq["Bonito Bitz"]);
	p[3] = mp("Ritzy Bitz", freq["Ritzy Bitz"]);
	sort(p, p + 4, Cmp);
	for (int i=0; i<4; i++) {
		if (p[i].s) cout << p[i].f << " " << p[i].s << "\n";
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