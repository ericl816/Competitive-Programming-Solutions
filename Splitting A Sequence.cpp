#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define ull unsigned long long
#define MAXM 1000000010
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
#ifdef DEBUG
	#define D(x...) printf(x)
#else
	#define D(x...)
#endif
using namespace std;

// Binary search

int N, M;
int A[MAXN];
ll ans = INF;

inline bool Calc (ll mid) {
	ll cnt = 1, tot = 0;
	for (int i=0; i<N; i++) {
		tot += A[i];
		if (tot > mid) {
			++cnt;
			tot = A[i];
		}
	}
	return cnt <= M;
}

int main (int argc, char const *argv[]) {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	ll lo = 0, hi = 0;
	for (int i=0, x; i<N; i++) {
		cin >> A[i];
		lo = max(lo, A[i]);
		hi += A[i];
	}
	while (lo <= hi) {
		ll mid = (lo + hi) >> 1;
		if (Calc(mid)) {
			ans = min(ans, mid);
			hi = mid - 1;
		}
		else lo = mid + 1;
	}
	cout << ans << "\n";
	return 0;
}

/*
5 3
4 2 4 5 1
*/

/* 
 * Look for:
 * the exact constraints (multiple sets are too slow for n=10^6 :( ) 
 * special cases (n=1?)
 * overflow (ll vs int?)
 * array bounds
 */