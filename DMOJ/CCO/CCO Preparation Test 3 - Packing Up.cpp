#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXN 2000010
#define INF 0x3f3f3f3f
#define min(a, b) (a) < (b) ? (a) : (b)
#define max(a, b) (a) < (b) ? (b) : (a)
#define t(x) (x) * (x)
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define mii map<int, int>
#define umii unordered_map<int, int>
#ifdef DEBUG
	#define D(x...) printf(x)
#else
	#define D(x...)
#endif
using namespace std;

ll N, L;
ll C[MAXN], DP[MAXN], PSA[MAXN];
deque<pair<ll, ll> > mq;

inline double Slope (const pair<ll, ll> &a, const pair<ll, ll> &b) {
	return (double) (a.f - b.f) / (double) (a.s - b.s);
}

int main () {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> L;
	for (int i=1; i<=N; i++) {
		cin >> C[i];
		PSA[i] = PSA[i - 1] + C[i];
	}
	mq.pb(mp(0, 0));
	for (int i=1; i<=N; i++) {
		ll gap = PSA[i] + i - L - 1;
		while (mq.size() >= 2 && Slope(mq[1], mq[0]) <= gap * 2) mq.pop_front();
		DP[i] = t(gap - mq.front().s) - t(mq.front().s) + mq.front().f;
		pair<ll, ll> line = pair<ll, ll>(DP[i] + t(PSA[i] + i), PSA[i] + i);
		while (mq.size() >= 2 && Slope(line, mq[mq.size() - 1]) <= Slope(mq[mq.size() - 1], mq[mq.size() - 2])) mq.pop_back();
		mq.pb(line);
	}
	cout << DP[N] << "\n";
	return 0;
}

/* 
 * Look for:
 * the exact constraints (multiple sets are too slow for n=10^6 :( ) 
 * special cases (n=1?)
 * overflow (ll vs int?)
 * array bounds
 */