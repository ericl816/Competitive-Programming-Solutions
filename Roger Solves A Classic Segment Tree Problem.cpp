#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define MAXN 50010
#define INF 0x3f3f3f3f
#define min(a, b) (a) < (b) ? (a) : (b)
#define max(a, b) (a) < (b) ? (b) : (a)
#define ll long long
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define mii map<int, int>
#define umii unordered_map<int, int>
using namespace std;

int N, Q;
int arr[MAXN], segmin[MAXN << 1], segmax[MAXN << 1];

inline ll maxsegQuery (int l, int r, int idx = 1) {
	l += N - 1;
	r += N - 1;
	ll ans = -INF;
	while (l <= r) {
		if (l & 1) {
			ans = max(ans, segmax[l]);
			l++;
		}
		if (!(r & 1)) {
			ans = max(ans, segmax[r]);
			r--;
		}
		l >>= 1;
		r >>= 1;
	}
	return ans;
}

inline ll minsegQuery (int l, int r, int idx = 1) {
	l += N - 1;
	r += N - 1;
	ll ans = INF;
	while (l <= r) {
		if (l & 1) {
			ans = min(ans, segmin[l]);
			l++;
		}
		if (!(r & 1)) {
			ans = min(ans, segmin[r]);
			r--;
		}
		l >>= 1;
		r >>= 1;
	}
	return ans;
}

int main () {
	scan(N); scan(Q);
	for (int i=1; i<=N; i++) {
		scan(arr[i]);
		segmin[i + N - 1] = segmax[i + N - 1] = arr[i];
	}
	for (int i=N - 1; i>0; i--) {
  		segmin[i] = min(segmin[i << 1], segmin[i << 1 | 1]);
  		segmax[i] = max(segmax[i << 1], segmax[i << 1 | 1]);
	}
	for (int i=0, a, b; i<Q; i++) {
		scan(a); scan(b);
		printf("%lld\n", maxsegQuery(a, b) - minsegQuery(a, b));
	}
	return 0;
}