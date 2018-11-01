#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define ull unsigned long long
#define MAXN 110
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
#ifdef DEBUG
	#define D(x...) printf(x)
#else
	#define D(x...)
#endif
using namespace std;

int T = 5, N, ans, diff1, diff2;
bool isPrime[MAXN];
vi primes;

inline void Sieve () {
	memset(isPrime, 1, sizeof(isPrime));
	isPrime[0] = isPrime[1] = 0;
	for (int i=2; i<=MAXN; i++) {
		if (isPrime[i]) {
			primes.pb(i);
			for (int j=i * 2; j<=MAXN; j+=i) isPrime[j] = 0;
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
	Sieve();
	while (T--) {
		cin >> N;
		int ind = lower_bound(primes.begin(), primes.end(), N) - primes.begin();
		if (~ind) {
			if (primes[ind] > N) {
				// cout << primes[ind] << " " << primes[ind - 2] << " " << primes[ind + 1] << endl;
				if (ind - 2 >= 0 && ind + 1 < primes.size()) {
					diff1 = abs(N - primes[ind - 2]), diff2 = abs(N - primes[ind + 1]);
					if (diff1 < diff2) cout << primes[ind - 2] << "\n";
					else if (diff2 < diff1) cout << primes[ind + 1] << "\n";
					else cout << (max(primes[ind - 2], primes[ind + 1])) << "\n";;
				}
				else if (ind - 2 >= 0) cout << primes[ind - 2] << "\n";
				else if (ind + 1 < primes.size()) cout << primes[ind + 1] << "\n";
			}
			else {
				// cout << primes[ind] << " " << primes[ind - 2] << " " << primes[ind + 2] << endl;
				if (ind - 2 >= 0 && ind + 2 < primes.size()) {
					diff1 = abs(N - primes[ind - 2]), diff2 = abs(N - primes[ind + 2]);
					if (diff1 < diff2) cout << primes[ind - 2] << "\n";
					else if (diff2 < diff1) cout << primes[ind + 2] << "\n";
					else cout << (max(primes[ind - 2], primes[ind + 2])) << "\n";;
				}
				else if (ind - 2 >= 0) cout << primes[ind - 2] << "\n";
				else if (ind + 2 < primes.size()) cout << primes[ind + 2] << "\n";
			}
		}
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