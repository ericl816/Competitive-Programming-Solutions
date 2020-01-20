#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXN 2010
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
using namespace std;

int N, R;
ll E, C1, V1, CA, CB, CM, VA, VB, VM, extra;
priority_queue<ll, vector<ll>, greater<ll> > pq[MAXN];
ll DP[MAXN];

int main () {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> R;
	for (int i=0; i<N; i++) {
		cin >> E >> C1 >> V1 >> CA >> CB >> CM >> VA >> VB >> VM;
		for (int j=0; j<E; j++) {
			if (C1 <= R) {
				if (C1 == 0) extra += V1;
				else {
					pq[C1].push(V1);
					if (pq[C1].size() * C1 > R) pq[C1].pop();
				}
			}
			C1 = 1LL * (C1 * CA + CB) % CM;
			V1 = 1LL * (V1 * VA + VB) % VM;
		}
	}
	// cout << C1 << " " << V1 << endl;
	for (int i=1; i<=R; i++) {
		while (!pq[i].empty()) {
			ll val = pq[i].top();
			pq[i].pop();
			for (int j=R; j; j--) if (j - i >= 0 && DP[j] <= DP[j - i] + val) DP[j] = DP[j - i] + val;
		}
	}
	cout << DP[R] + extra << "\n";
	return 0;
}

/* 
 * Look for:
 * the exact constraints (multiple sets are too slow for n=10^6 :( ) 
 * special cases (n=1?)
 * overflow (ll vs int?)
 * array bounds
 */