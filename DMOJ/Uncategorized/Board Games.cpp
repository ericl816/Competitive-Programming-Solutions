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
#define MAXN 10000010
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) < (b) ? (b) : (a))
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

ll N, M;
queue<pair<ll, ll> > q;
bitset<MAXN> vis;

inline bool isValid (ll x) {
	return x >= 1 && x <= 1e7;
}

int main (int argc, char const *argv[]) {
	#ifdef NOT_DMOJ
	freopen("DATA.in", "r", stdin);
	freopen("DATA.out", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	q.push(mp(N, 0));
	vis[N] = 1;
	while (!q.empty()) {
		pii curr = q.front(); q.pop();
		if (curr.f == M) {
			cout << curr.s << "\n";
			return 0;
		}
		if (curr.f * 3 == M || curr.f - 1 == M || curr.f - 3 == M || (curr.f % 2 == 0 && curr.f / 2 == M)) {
			cout << curr.s + 1 << "\n";
			return 0;
		}
		if (isValid(curr.f * 3) && !vis[curr.f * 3]) {
			vis[curr.f * 3] = 1;
			q.push(mp(curr.f * 3, curr.s + 1));
		}
		if (isValid(curr.f - 1) && !vis[curr.f - 1]) {
			vis[curr.f - 1] = 1;
			q.push(mp(curr.f - 1, curr.s + 1));
		}
		if (isValid(curr.f - 3) && !vis[curr.f - 3]) {
			vis[curr.f - 3] = 1;
			q.push(mp(curr.f - 3, curr.s + 1));
		}
		if (curr.f % 2 == 0 && isValid(curr.f / 2)) {
			vis[curr.f / 2] = 1;
			q.push(mp(curr.f / 2, curr.s + 1));
		}
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