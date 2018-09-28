#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define ull unsigned long long
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
#define println cout << "\n";
#ifdef DEBUG
	#define D(x...) printf(x)
#else
	#define D(x...)
#endif
using namespace std;

int N, K, x;
vi half1, half2;
vector<ll> sum1, sum2;
ll ans;

inline void Generate () {
	sum1.pb(0);
	for (size_t i=0; i<half1.size(); i++) {
		int len = sum1.size();
		for (size_t j=0; j<len; j++) {
			sum1.pb(sum1[j] + half1[i]);
		}
	}
	sum2.pb(0);
	for (size_t i=0; i<half2.size(); i++) {
		int len = sum2.size();
		for (size_t j=0; j<len; j++) {
			sum2.pb(sum2[j] + half2[i]);
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
	cin >> N >> K;
	for (int i=0; i<(N >> 1); i++) {
		cin >> x;
		half1.pb(x);
	}
	for (int i=(N >> 1); i<N; i++) {
		cin >> x;
		half2.pb(x);
	}
	Generate();
	sort(sum1.begin(), sum1.end());
	sort(sum2.begin(), sum2.end());
	// for (auto i : sum1) cout << "1st half" << i << "\n";
	// for (auto i : sum2) cout << "2nd half" << i << "\n";
	for (size_t i=0; i<sum1.size(); i++) {
		ll tar = K - sum1[i];
		int lo = 0, hi = sum2.size() - 1;
		while (lo <= hi) {
			int mid = (lo + hi) >> 1;
			// cout << sum2[mid] << "\n";
			if (sum2[mid] <= tar) lo = mid + 1;
			else hi = mid - 1;
		}
		ans += lo;
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