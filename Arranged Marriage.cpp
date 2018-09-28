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

ll N, ans;
int B, A;

int main (int argc, char const *argv[]) {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> B >> A;
	// (A + Bx)(N - x) = AN - Ax + BNx - Bx^2
	// d/dx(f(x)) = (B)(N - x) - (A + Bx)
	// d/dx(f(x)) = 0 => BN-Bx-A-Bx=0
	// => -2Bx = A - BN
	// => x = (A - BN) / -2B;
	ll tmp = (ll) round(-1.0 * (A - B * N) / (2 * B));
	ans = (A + B * tmp) * (N - tmp);
	if (ans < 0) ans = A * N;
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
