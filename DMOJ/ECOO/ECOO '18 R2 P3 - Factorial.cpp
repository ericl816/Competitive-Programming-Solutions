#include <bits/stdc++.h>
#define ll long long
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define MAXN 1000010
#define INF 0x3f3f3f3f
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define mii map<int, int>
#define umii unordered_map<int, int>
using namespace std;

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

void Do_Test_Cases () {
	int TEST_CASES = 10;
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
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("DATA11.txt", "r", stdin);
    Sieve(MAXN);
    Do_Test_Cases();
    return 0;
}