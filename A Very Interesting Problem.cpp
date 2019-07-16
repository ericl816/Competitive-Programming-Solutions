#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define ull unsigned long long
#define MAXN 100010
#define INF 0x3f3f3f3f
#define min(a, b) (a) < (b) ? (a) : (b)
#define max(a, b) (a) < (b) ? (b) : (a)
#define vi vector<int>
#define vll vector<ll>
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

int N, Q, op, a, b;

struct Disjoint {
private:
	int N, cnt;
	vi lead, rank;

public:
	Disjoint (int N) : N(N), lead(N + 1), rank(N + 1) { }

	void make_Set () {
		cnt = N;
		for (int i=0; i<N; i++) {
		  lead[i] = i;
		  rank[i] = 0;
		}
	}

	int Find (int x) {
		while (lead[x] ^ x) {
			lead[x] = lead[lead[x]];
			x = lead[x];
		}
		return x;
	}

	bool Merge (int x, int y) {
		return Find(x) ^ Find(y);
	}

	void Union (int x, int y) {
		int c = Find(x);
		int d = Find(y);
		if (Merge(x, y)) {
			if (rank[c] > rank[d]) {
				lead[d] = c;
				rank[c] += rank[d];
			}
			else {
				lead[c] = d;
				rank[d] += rank[c];
			}
		}
	}
};

Disjoint ds(MAXN);

int main (int argc, char const *argv[]) {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ds.make_Set();
	cin >> N >> Q;
	while (Q--) {
		cin >> op >> a >> b;
		if (op == 1) ds.Union(a, b);
		else cout << (ds.Merge(a, b) ? "NO" : "YES") << "\n";
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