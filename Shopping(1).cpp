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
#ifdef DEBUG
	#define D(x...) printf(x)
#else
	#define D(x...)
#endif
using namespace std;

int n, q;
ll l[MAXN], r[MAXN], v[MAXN], a[MAXN];
vector<pair<ll, ll> > vec[MAXN];
priority_queue<pair<ll, ll> > pq;

int main (int argc, char const *argv[]) {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> q;
	for (int i=0; i<n; i++) cin >> a[i];
	for (int i=0; i<q; i++) {
		cin >> v[i] >> l[i] >> r[i];
		--l[i], --r[i];
		if (l[i] <= r[i]) vec[l[i]].pb(mp(v[i], i));
	}
	for (int i=0; i<n; i++) {
		for (auto i : vec[i]) pq.push(i);
		while (!pq.empty() && pq.top().f >= a[i]) {
			pii curr = pq.top();
			pq.pop();
			ll ind = curr.s;
			if (i <= r[ind]) {
				v[ind] %= a[i];
				pq.push(mp(v[ind], ind));
			} 
		}
	}
	for (int i=0; i<q; i++) cout << v[i] << "\n";
	return 0;
}

/* 
 * Look for:
 * the exact constraints (multiple sets are too slow for n=10^6 :( ) 
 * special cases (n=1?)
 * overflow (ll vs int?)
 * array bounds
 */