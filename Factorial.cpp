#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define ull unsigned long long
#define MAXN 1000010
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

int TEST_CASES = 10;

ll K, M, N;
bool sieve[MAXN];
vector<ll> primes;

inline void Sieve (int N) {
	memset(sieve, 0, sizeof(sieve));
	for (int i=2; i<N; i++) {
		if (!sieve[i]) {
			for (int j=i * 2; j<N; j += i) sieve[j] = 1;
			primes.pb(i);
		}
	}
}

// First element = prime factor of K^M, Second element = number of prime factors
inline vector<pair<ll, ll> > Check () {
	vector<pair<ll, ll> > res;
	for (size_t i=0; i<primes.size(); i++) {
		ll &next = primes[i];
		ll num = 0;
		while (K % next == 0) {
			K /= next;
			num++;
		}
		num *= M;
		if (num) res.pb(mp(next, num));
	}
	return res;
}

inline void Do_Test_Cases () {
	while (TEST_CASES--) {
		cin >> K >> M;
		ll lo = 2, hi = 1e18;
		vector<pair<ll, ll> > factors = Check();
		while (lo <= hi) {
			ll mid = (lo + hi) >> 1;
			bool flag = 1;
			for (size_t i=0; i<factors.size(); i++) {
				pair<ll, ll> &next = factors[i];
				ll fact = next.f, cnt = 0LL;
				// Get number of prime factors of next.f in mid! (factorial)
				while (mid / fact) {
					cnt += mid / fact;
					fact *= next.f;
				}
				if (cnt < next.s) flag = 0;
			}
			if (flag) hi = mid - 1;
			else lo = mid + 1;
		}
		cout << lo << "\n";
	}
}

int main () {
	#ifdef NOT_DMOJ
	freopen("DATA11.txt", "r", stdin);
	freopen("DATA11out.txt", "w", stdout);
	#endif // NOT_DMOJ
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Sieve(MAXN);
    Do_Test_Cases();
    return 0;
}