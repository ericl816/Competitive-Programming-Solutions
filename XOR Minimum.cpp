#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXN 100010
#define SIZE 32
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

// Actual solution involves using a trie

int N, Q, x, len = 1;
int idx[MAXN * SIZE];
int trie[2][MAXN * SIZE];

inline void insert (int ind, int bit) {
	int node = 0;
	for (int i=SIZE - 1; i>=0; i--) {
		bool flag = bit & (1 << i);
		if (!trie[flag][node]) trie[flag][node] = len++;
		node = trie[flag][node];
	}
	if (!~idx[node]) idx[node] = ind;
}

inline int query (int bit) {
	int node = 0;
	for (int i=SIZE - 1; i>=0; i--) {
		bool flag = bit & (1 << i);
		if (!trie[flag][node]) flag ^= 1;
		node = trie[flag][node];
	}
	return idx[node];
}


int main () {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> Q;
	memset(idx, -1, sizeof(idx));
	for (int i=0, a; i<N; i++) {
		cin >> a;
		insert(i, a);
	}
	int mask = 0;
	while (Q--) {
		cin >> x;
		int ans = query(x ^ mask);
		cout << ans << "\n";
		mask ^= x;
	}
	return 0;
}

/* 
 * Look for:
 * the exact constraints (multiple sets are too slow for n=10^6 :( ) 
 * special cases (n=1?)
 * overflow (ll vs int?)
 * array bounds
 */