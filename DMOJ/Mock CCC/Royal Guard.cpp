#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define ull unsigned long long
#define MAXN 200010
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
#define DEBUG 1
#ifdef DEBUG
	#define D(x...) printf(x)
#else
	#define D(x...)
#endif
using namespace std;

int N, M, x, y, prevx, prevy;
pii ptx[MAXN], pty[MAXN];
ll ans;

inline bool Cmpx (pii a, pii b) {
	if (a.f ^ b.f) return a.f < b.f;
	return a.s < b.s;
}

inline bool Cmpy (pii a, pii b) {
	if (a.s ^ b.s) return a.s < b.s;
	return a.f < b.f;
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
		cin >> x >> y;
		ptx[i] = mp(x, y);
		pty[i] = mp(x, y);
	}
	sort(ptx, ptx + N, Cmpx);
	sort(pty, pty + N, Cmpy);
	cin >> M >> prevx >> prevy;
	for (int i=1; i<M; i++) {
		cin >> x >> y;
		if (prevx == x) {
			int ind1 = upper_bound(ptx, ptx + N, mp(x, max(y, prevy)), Cmpx) - ptx, ind2 = lower_bound(ptx, ptx + N, mp(prevx, min(y, prevy)), Cmpx) - ptx;
			ans += abs(ind2 - ind1);
		}
		else if (prevy == y) {
			int ind1 = upper_bound(pty, pty + N, mp(max(x, prevx), y), Cmpy) - pty, ind2 = lower_bound(pty, pty + N, mp(min(x, prevx), y), Cmpy) - pty;
			ans += abs(ind2 - ind1);
		}
		prevx = x, prevy = y;
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