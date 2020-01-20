#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define ull unsigned long long
#define MAXN 41
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
#define complete_unique(x) x.erase(unique(allof(x)), x.end())
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

int T;
string a, b, c;
int dict[MAXN];
bool flag[MAXN], vis[MAXN];
vector<char> vec;

inline bool Recur (int idx) {
	if (idx >= vec.size()) {
		int res = 0;
		for (size_t i=0; i<c.size(); i++) {
			if (i < a.size()) res += dict[(int) a[i] - '0'];
			if (i < b.size()) res += dict[(int) b[i] - '0'];
			int C = (int) c[i] - '0';
			if (dict[C] ^ res % 10) return 0;
			res /= 10;
		}
		if (!res) {
			for (size_t i=0; i<a.size(); i++) cout << dict[(int) a[a.size() - i - 1] - '0'];
			cout << "\n";
			for (size_t i=0; i<b.size(); i++) cout << dict[(int) b[b.size() - i - 1] - '0'];
			cout << "\n";
			for (size_t i=0; i<c.size(); i++) cout << dict[(int) c[c.size() - i - 1] - '0'];
			cout << "\n";
			return 1;
		}
		return 0;
	}
	for (size_t i=(int) flag[(int) vec[idx] - '0']; i<=9; i++) {
		if (!vis[i]) {
			vis[i] = 1;
			dict[(int) vec[idx] - '0'] = i;
			bool res = Recur(idx + 1);
			vis[i] = 0;
			if (res) return 1;
		}
	}
	return 0;
}

int main (int argc, char const *argv[]) {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while (T--) {
		memset(dict, 0, sizeof(dict));
		memset(vis, 0, sizeof(vis));
		memset(flag, 0, sizeof(flag));
		cin >> a >> b >> c;
		vec.clear();
		flag[(int) a[0] - '0'] = flag[(int) b[0] - '0'] = flag[(int) c[0] - '0'] = 1;
		reverse(allof(a)), reverse(allof(b)), reverse(allof(c));
		for (auto i : a) vec.pb(i);
		for (auto i : b) vec.pb(i);
		for (auto i : c) vec.pb(i);
		sort(allof(vec));
		complete_unique(vec);
		Recur(0);
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