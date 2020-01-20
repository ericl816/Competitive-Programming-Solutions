#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define ull unsigned long long
#define MAXM 17
#define MAXN 100010
#define INF 0x3f3f3f3f
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

// Essentialy RMQ + Sliding Window
int N, K, Q, l, r, ind;
int A[MAXN], L[MAXN], R[MAXN];
int RMQ[MAXM][MAXN];
deque<pii> minq, maxq;

inline int Query (int x, int y) {
	int SIZE = log(y - x + 1) / log(2);
	if (R[RMQ[SIZE][x]] >= R[RMQ[SIZE][y - (1 << SIZE) + 1]]) return RMQ[SIZE][x];
	return RMQ[SIZE][y - (1 << SIZE) + 1];
}

int main (int argc, char const *argv[]) {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> K;
	for (int i=0; i<N; i++) {
		cin >> A[i];
		while (!minq.empty() && A[i] < minq.back().f) minq.pop_back();
		minq.pb(mp(A[i], i));
		while (!maxq.empty() && A[i] > maxq.back().f) maxq.pop_back();
		maxq.pb(mp(A[i], i));
		while (abs(maxq.front().f - minq.front().f) > K) {
			if (!minq.empty() && minq.front().s == ind) minq.pop_front();
			if (!maxq.empty() && maxq.front().s == ind) maxq.pop_front();
			R[ind] = i - ind;
			++ind;
		}
		L[i] = i - ind + 1;
	}
	// D("%d\n", ind);
	for (int i=ind; i<N; i++) R[i] = N - i;
	for (int i=0; i<N; i++) RMQ[0][i] = i;
	for (int i=1; (1 << i)<=N; i++) {
		for (int j=0; j + (1 << i)<=N; j++) {
			if (R[RMQ[i - 1][j]] >= R[RMQ[i - 1][j + (1 << (i - 1))]]) RMQ[i][j] = RMQ[i - 1][j];
			else RMQ[i][j] = RMQ[i - 1][j + (1 << (i - 1))];
		}
	}
	cin >> Q;
	while (Q--) {
		cin >> l >> r;
		--l, --r;
		int val1 = min(L[r], r - l + 1), val2 = max(l, r - L[r] + 1);
		if (l == val2) {
			cout << val2 + 1 << " " << val1 + val2 << "\n";
			continue;
		}
		// D("%d %d\n", val1, val2);
		int res = Query(l, val2 - 1);
		// D("%d\n", res);
		if (min(R[res], r - res + 1) >= val1) {
			val1 = min(R[res], r - res + 1);
			val2 = res;
		}
		cout << val2 + 1 << " " << val1 + val2 << "\n";
	}
	return 0;
}

/*
7 4
3 6 8 4 3 6 1
3
2 6
3 6
1 3
*/

/* 
 * Look for:
 * the exact constraints (multiple sets are too slow for n=10^6 :( ) 
 * special cases (n=1?)
 * overflow (ll vs int?)
 * array bounds
 */