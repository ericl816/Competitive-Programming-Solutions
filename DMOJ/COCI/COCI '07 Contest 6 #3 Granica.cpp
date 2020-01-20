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

int N, gcd, idx, minn = INF;
int a[MAXN], diff[MAXN];
vector<ll> v;

inline int GCD (int a, int b) {
	return b == 0 ? a : GCD(b, a % b);
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
	for (int i=0; i<N; i++) {
		cin >> a[i];
		minn = min(minn, a[i]);
	}
	for (int i=0; i<N; i++) {
		if (a[i] ^ minn) diff[idx++] = abs(a[i] - minn);
	}
	int gcd = (N == 2) ? diff[0] : GCD(diff[0], diff[1]);
	for (int i=2; i<N; i++) gcd = GCD(gcd, diff[i]);
	for (int i=1; i * i<=(gcd); i++) {
		if (i == 1) {
			cout << gcd << " ";
			continue;
		}
		if (gcd % i == 0) {
			cout << i << " ";
			if (gcd ^ i * i) cout << gcd / i << " ";
		}
	}
	cout << "\n";
	return 0;
}

/* 
 * Look for:
 * the exact constraints (multiple sets are too slow for n=10^6 :( ) 
 * special cases (n=1?)
 * overflow (ll vs int?)
 * array bounds
 */