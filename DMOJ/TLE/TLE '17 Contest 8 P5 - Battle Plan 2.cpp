#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXK 60
#define MAXM 21 // log2(200010)
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
using namespace std;

int N, K, Q, op, l, r, SIZE;
ll a[MAXN], b[MAXN], ans[MAXN];
int sparse[MAXM][MAXN], segmax[MAXM][MAXN];
vector< pair <int, pii> > adj[MAXK];

inline void Build_ST (int x) {
	int idx = 1;
	ll sum = 0;
	for (int i=1; i<=N; i++) {
		sum += a[i];
		while (idx < i && x < sum) {
			sparse[0][idx] = i;
			sum -= a[idx++];
		}
	}
	sparse[0][N + 1] = N + 1;
	for (int i=1; i<=SIZE; i++) {
		for (int j=1; j<=N; j++) {
			sparse[i][j] = sparse[i - 1][sparse[i - 1][j]];
		}
	}
}

inline int Query (int l, int r) {
	int num = 0, idx = l;
	for (int i=SIZE; i>=0; i--) {
		if (sparse[i][idx] && sparse[i][idx] <= r) {
			idx = sparse[i][idx];
			num += 1 << i;
		}
	}
	return num + 1;
}


inline void Build_Max_ST () {
	for (int i=1; i<=N; i++) segmax[0][i] = a[i];
	for (int i=1; i<=SIZE; i++) {
		for (int j=1; j + (1 << i) - 1<=N; j++) {
			segmax[i][j] = max(segmax[i - 1][j], segmax[i - 1][j + (1 << (i - 1))]);
		}
	}
}

inline int Max_Query (int l, int r) {
	int SIZE1 = log(r - l + 1) / log(2);
	int ans = max(segmax[SIZE1][l], segmax[SIZE1][r - (1 << SIZE1) + 1]);
	return ans;
}

int main () {
	scan(N); scan(K); scan(Q);
	SIZE = 32 - __builtin_clz(N);
	for (int i=1; i<=N; i++) scan(a[i]);
	Build_Max_ST();
	for (int i=1; i<=K; i++) scan(b[i]);
	for (int i=0; i<Q; i++) {
		scan(op); scan(l); scan(r);
		adj[op].pb(mp(i, mp(l, r)));
	}
	for (int i=1; i<=K; i++) {
		Build_ST(b[i]);
		for (size_t j=0; j<adj[i].size(); j++) {
			pair<int, pii> &next = adj[i][j];
			int ind = next.f, left = next.s.f, right = next.s.s;
			// printf("%d %d %d\n", ind, left, right);
			int seg_max = Max_Query(left, right);
			// printf("%d\n", seg_max);
			if (b[i] < seg_max) ans[ind] = -1;
			else ans[ind] = Query(left, right);
			// printf("%d\n", Query(left, right));
		}
	}
	for (int i=0; i<Q; i++) printf("%lld\n", ans[i]);
	return 0;
}