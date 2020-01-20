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
inline ll PowMod (ll a, ll b, ll MOD) { ll val = 1; while (b) { if (b & 1) val = (val * a) % MOD; a = (a * a) % MOD; b >>= 1; } return val; }

int N, K, pos, neg;
ll ans = 1LL;
int a[MAXN];

int main (int argc, char const *argv[]) {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> K;
	for (int i=0; i<N; i++) {
		cin >> a[i];
		neg += (a[i] < 0 ? 1 : 0);
		pos += (a[i] > 0 ? 1 : 0);
	}
	ll res = -1LL, lo = 0LL, hi = 0LL;
	sort(a, a + N);
	for (int i=1; i<N; i++) {
		if (a[i] > 0) {
			res = a[i - 1];
			lo = i - 2;
			hi = i;
		}
	}
	if (!~res) {
		res = a[N - 1];
		lo = N - 2;
		hi = N;
	}
	ll indl = 0LL, indr = N - 1;
	if (N == K) {
		for (int i=0; i<N; i++) ans *= a[i];
	}
	else {
		while (K) {
			if (!(K & 1)) {
				if (indl + 1 < N && indr - 1 >= 0) {
					ll prodl = a[indl] * a[indl + 1], prodr = a[indr - 1] * a[indr];
					if (prodl > prodr) {
						indl += 2;
						ans *= prodl;
					}
					else {
						indr -= 2;
						ans *= prodr;
					}
					K -= 2;
				}
				else if (indl + 1 < N) {
					ll prodl = a[prodl] * a[prodl + 1];
					ans *= prodl;
					indl += 2;
					K -= 2;
				}
				else if (indr - 1 >= 0) {
					ll prodr = a[indr - 1] * a[indr];
					ans *= prodr;
					indr -= 2;
					K -= 2;
				}
				else {
					ll prod = a[indl] * a[indr];
					ans *= prod;
					K -= 2;
				}
			}
			else {
				if (pos >= K || pos > 0) {
					ans *= a[N - 1];
					indr--;
					K--;
				}
				else {
					for (int i=N - 1; i>=0; i--) {
						ans *= a[i];
						--K;
						if (!K) break;
					}
				}
			}
		}
	}
	cout << ans << "\n";
	return 0;
}

/* 
 * Look for:
 * the exact constraints (multiple sets are too slow for n=10^6 :( ) 
 * special cases (n=1?)
 * overflow (ll vs int?)
 * array bounds
 */