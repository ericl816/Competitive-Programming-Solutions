#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
// #include <bits/stdc++.h>
#include "/Users/ericliu/Desktop/Competitive-Programming-Templates/stdc++.h"
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define ull unsigned long long
#define MAXN 1000010
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

struct Disjoint {
private:
	int N;
	vi lead, rank;

public:
	Disjoint(int N) : N(N), lead(N + 1), rank(N + 1) { }

	inline void make_Set () {
		for (int i=1; i<=N; i++) {
			lead[i] = i;
			rank[i] = 0;
		}
	}
	
	inline inline int Find (int x) {
		while (x ^ lead[x]) {
			lead[x] = lead[lead[x]];
			x = lead[x];
		}
		return x;
	}

	inline bool Merge (int x, int y) {
		return Find(x) ^ Find(y);
	}

	inline void Union (int x, int y) {
		int c = Find(x);
		int d = Find(y);
		if (c ^ d) {
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

	inline int getSize (int x) {
		return lead[x];
	}
};

Disjoint ds(MAXN);

int N, M, a, b;
ll sum;
vi adj[MAXN];
ll DP[MAXN];
bool vis[MAXN];

int main (int argc, char const *argv[]) {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ds.make_Set();
	cin >> N >> M;
	for (int i=0; i<M; i++) {
		cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
		if (ds.Merge(a, b)) ds.Union(a, b);
	}
	for (int i=1; i<=N; i++) sum += ds.getSize(i);
	cout << sum << "\n";
	return 0;
}

/* 
 * Look for:
 * the exact constraints (multiple sets are too slow for n=10^6 :( ) 
 * special cases (n=1?)
 * overflow (ll vs int?)
 * array bounds
 */