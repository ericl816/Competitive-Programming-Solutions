#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define ull unsigned long long
#define MAXN 47
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

int T = 5, x;
int fib[MAXN];

int main (int argc, char const *argv[]) {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	fib[0] = 0;
	fib[1] = fib[2] = 1;
	for (int i=3; i<MAXN; i++) fib[i] = fib[i - 1] + fib[i - 2];
	while (T--) {
		cin >> x;
		int ind1 = upper_bound(fib, fib + MAXN, x) - fib, ind2 = ind1 - 1;
		if (~ind1 && ~ind2) {
			if (abs(fib[ind1] - x) == abs(fib[ind2] - x)) cout << fib[ind1] << "\n";
			else if (abs(fib[ind1] - x) < abs(fib[ind2] - x)) cout << fib[ind1] << "\n";
			else cout << fib[ind2] << "\n";
		}
		else if (~ind1) cout << fib[ind1] << "\n";
		else cout << fib[ind2] << "\n";
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