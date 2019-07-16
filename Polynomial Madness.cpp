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

int N, D;
vll coeff;
ll c;

inline ll Fpow (ll x, ll y) {
    if (y == 0) return 1LL;
    if (y == 1) return 1LL * x;
    if (y & 1) return x * Fpow(x * x, y >> 1);
    else return Fpow(x * x, y >> 1);
}

// Evaluates polynomial given degree + coefficients
inline ll fun1 (vll &v, ll x) {
	ll ans = 0LL;
	for (size_t i=0; i<v.size(); i++) ans += Fpow(x, i) * v[i];
	return ans;
}

// Divides the 2 polynomials
inline vll fun2 (vll &v, ll x) {
	int sz = v.size() - 1;
	vll res(v.size());
	res[sz - 1] = v[sz];
	for (int i=sz - 2; i>=0; i--) res[i] = x * res[i + 1] + v[i + 1];
	return res;
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
	while (N--) {
		cin >> D;
		coeff.clear();
		for (int i=0; i<=D; i++) {
			cin >> c;
			coeff.pb(c);
		}
		reverse(coeff.begin(), coeff.end());
		for (int i=-150; i<=150; i++) {
			while (fun1(coeff, i) == 0) {
				cout << i << " ";
				coeff = fun2(coeff, i);
			}
		}
		cout << "\n";
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