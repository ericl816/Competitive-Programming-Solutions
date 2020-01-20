#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(y) do{while((y=getchar())<'0'); for(y-='0'; '0'<=(_=getchar()); y=(y<<3)+(y<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXN 16777226
#define INF 0x3f3f3f3f3f3f3f3f
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

int N, K, last;
int idx[MAXN];
ll n, ans = INF;
ll DP[MAXN];
vi steps;
deque<pair<ll, int>> minq;

int main () {
	scan(N);
	scan(K);
	minq.pb(mp(0, 0));
	for (int i=1; i<=N; i++) {
		scan(n);
		while (!minq.empty() && minq.front().s < i - K) minq.pop_front();
		DP[i] = minq.front().f + n;
		idx[i] = minq.front().s;
		while (!minq.empty() && minq.back().f >= DP[i]) minq.pop_back();
		minq.pb(mp(DP[i], i));
	}
	for (int i=N - K + 1; i<=N; i++) {
	    if (DP[i] <= ans) {
	        ans = DP[i];
	        last = i;
	    }
	}
	while (last) {
		steps.pb(last);
		last = idx[last];
	}
	printf("%lld\n", ans);
	for (int i=steps.size() - 1; i>=0; i--) printf("%d ", steps[i]);
	return 0;
}