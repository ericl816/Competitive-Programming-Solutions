#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXN 1000010
#define INF 0x3f3f3f3f
#define min(a, b) (a) < (b) ? (a) : (b)
#define max(a, b) (a) < (b) ? (b) : (a)
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define mii map<int, int>
#define umii unordered_map<int, int>
using namespace std;

int N;
bool sieve[MAXN];
vi primes, ans;

inline void Sieve () {
	memset(sieve, 0, sizeof(sieve));
	for (int i=2; i<MAXN; i++) {
		if (!sieve[i]) {
			for (int j=i + i; j<MAXN; j+=i) {
				sieve[j] = 1;
			}
			primes.pb(i);
		}
	}
}

int main () {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	Sieve();
	for (int i=0; i + 1<primes.size(); i++) if (primes[i + 1] <= N && primes[i] + 2 == primes[i + 1]) ans.pb(primes[i]);
	cout << ans.size() << "\n";
	for (auto x : ans) cout << 2 << " " << x << "\n";
	return 0;
}