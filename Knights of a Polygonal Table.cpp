#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
// #include <bits/stdc++.h>
#include "/Users/ericliu/Desktop/Competitive-Programming-Templates/stdc++.h"
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXN 100010
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

int n, k;
int p[MAXN], c[MAXN];
vector<pii> ind;
priority_queue<ll, vector<ll>, greater<ll> > pq;
ll sum;
ll ans[MAXN];

inline void add (ll num) {
	if (k == 0) return;
	if (pq.size() < k) {
			pq.push(num);
			sum += num;
		}
		else {
			if (pq.top() < num) {
				sum -= pq.top();
				sum += num;
				pq.pop();
				pq.push(num);
			}
		}
}

inline bool Cmp (pii &a, pii &b) {
	return a.f < b.f;
}

int main () {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	for (int i=0; i<n; i++) {
		cin >> p[i];
		ind.pb(mp(p[i], i));
	}
	for (int i=0; i<n; i++) cin >> c[i];
	sort(ind.begin(), ind.end(), Cmp);
	for (size_t i=0; i<ind.size(); i++) {
		int idx = ind[i].s;
		ans[idx] = sum + c[idx];
		add(c[idx]);
	}
	for (int i=0; i<n; i++) cout << ans[i] << " ";
	cout << endl;
	return 0;
}