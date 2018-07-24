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

/* Solution involves using a "Sliding-Range Minimum Query" approach, similar to Pizza Bag
 * Use a deque to keep track of the minimum number of steps required
 * Is also a Dynamic Programming problem
 * The K, in the input (can jump at most K steps) makes the Sliding-Range Minimum Query approach very obvious
 * This is similar to how you can only take up to K pizza slices in the Pizza Bag problem statement
 */

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
	// Perform Sldiing-Range Minimum Query
	for (int i=1; i<=N; i++) {
		scan(n);
		while (!minq.empty() && minq.front().s < i - K) minq.pop_front();
		DP[i] = minq.front().f + n; // Hop forwards to next stone
		idx[i] = minq.front().s;
		// Pop the back element if it's greater than or equal to the currently stored element in DP array
		// This is becasue we want to store the greatest elements at the top of the deque
		while (!minq.empty() && minq.back().f >= DP[i]) minq.pop_back();
		minq.pb(mp(DP[i], i));
	}
	// Range [N - K, N] is inclusive (starting with index 1)
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
	reverse(steps.begin(), steps.end());
	// Indices are 0-indexed!
	for (auto next : steps) printf("%d ", next);
	return 0;
}