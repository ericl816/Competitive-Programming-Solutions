#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC optimize "omit-frame-pointer"
#pragma GCC optimize "prefetch-loop-arrays"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,aes,sse4a,sse4.1,sse4.2,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define ull unsigned long long
#define MAXK 6
#define MAXN 500010
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
#define umii unordered_map<int, int>w
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

int N, K, src = -1, dest = -1;
string s[MAXN];
int l[MAXK], indeg[MAXN], outdeg[MAXN];
vi euler_path;
vi adj[MAXN];
stack<int> st;

inline bool noPath () {
	bool flag = 1;
	for (int i=0; i<l[K - 1]; i++) {
		flag &= indeg[i] == outdeg[i];
		if (indeg[i] == outdeg[i] + 1) {
			if (~dest) return 1;
			else dest = i;
		}
		else if (indeg[i] + 1 == outdeg[i]) {
			if (~src) return 1;
			else src = i;
		}
		else if (indeg[i] ^ outdeg[i]) return 1;
	}
	return flag;
}

int main (int argc, char const *argv[]) {
	#ifdef NOT_DMOJ
	freopen("DATA.in", "r", stdin);
	freopen("DATA.out", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> K;
	for (int i=0; i<N; i++) cin >> s[i];
	if (K == 1) {
		string ans = "";
		for (int i=0; i<N; i++) ans += s[i];
		cout << ans << "\n";
		return 0;
	}
	l[0] = 1;
	for (int i=1; i<K; i++) l[i] = 26 * l[i - 1];
	for (int i=0; i<N; i++) {
		int res = 0;
		for (int j=0; j<s[i].size(); j++) {
			res *= 26, res += s[i][j] - 'a';
		}
		int x = res / 26;
		int y = res % l[K - 1];
		adj[x].pb(y);
		indeg[y]++, outdeg[x]++;
	}
	if (noPath()) {
		cout << -1 << "\n";
		return 0;
	}
	st.push(src);
	while (!st.empty()) {
		int curr = st.top();
		if (adj[curr].empty()) {
			euler_path.pb(curr);
			st.pop();
		}
		else {
			st.push(adj[curr].back());
			adj[curr].pop_back();
		}
	}
	reverse(allof(euler_path));
	// D("%d\n", euler_path.size());
	for (int i=K - 2; i>=1; i--) {
		char ch = 'a' + (euler_path[0] / l[i]) % 26;
		cout << ch;
	}
	for (auto i : euler_path) {
		char ch = 'a' + i % 26;
		cout << ch;
	}
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