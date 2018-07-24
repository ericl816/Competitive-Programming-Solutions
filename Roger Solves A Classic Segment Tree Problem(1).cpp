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

int N, Q, a, b;
ll arr[MAXN], tree1[MAXN * 3], tree2[MAXN * 3];

inline void Push_Up (int idx) {
	tree1[idx] = min(tree1[idx << 1], tree1[idx << 1 | 1]);
	tree2[idx] = max(tree2[idx << 1], tree2[idx << 1 | 1]);
}

inline void Build (int idx, int l, int r) {
	if (l == r) {
		tree1[idx] = tree2[idx] = arr[l];
		return;
	}
	int mid = (l + r) >> 1;
	Build(idx << 1, l, mid);
	Build(idx << 1 | 1, mid + 1, r);
	Push_Up(idx);
}

inline ll MinQuery (int idx, int l, int r, int l1, int r1) {
	if (l > r1 || r < l1) return INF;
	else if (l >= l1 && r <= r1) return tree1[idx];
	int mid = (l + r) >> 1;
	return min(MinQuery(idx << 1, l, mid, l1, r1), MinQuery(idx << 1 | 1, mid + 1, r, l1, r1));
}

inline ll MaxQuery (int idx, int l, int r, int l1, int r1) {
	if (l > r1 || r < l1) return -INF;
	else if (l >= l1 && r <= r1) return tree2[idx];
	int mid = (l + r) >> 1;
	return max(MaxQuery(idx << 1, l, mid, l1, r1), MaxQuery(idx << 1 | 1, mid + 1, r, l1, r1));
}

int main () {
	scan(N); scan(Q);
	for (int i=1; i<=N; i++) scan(arr[i]);
	Build(1, 1, N);
	for (int i=0; i<Q; i++) {
		scan(a); scan(b);
		printf("%lld\n", MaxQuery(1, 1, N, a, b) - MinQuery(1, 1, N, a, b));
	}
	return 0;
}