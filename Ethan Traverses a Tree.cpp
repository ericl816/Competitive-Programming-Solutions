#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXN 2010
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define EPS 1e=9
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

int T, N, K;
int A[MAXN], B[MAXN];
bool vis[MAXN];
vi pre_nodes, post_nodes; // Pre-order and Post-order traversals

struct Disjoint {
private:
	int N;
	vi lead, rank;

public:
	Disjoint (int N) : N(N), lead(N + 1), rank(N + 1) { }

	inline void make_Set () {
		for (int i=0; i<=N; i++) {
			lead[i] = i;
			rank[i] = 0;
		}
	}

	inline int Find (int x) {
		while (lead[x] ^ x) {
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

// Used for Pre and Post Order Traversals
inline void DFS (int node) {
	if (vis[node]) return;
	vis[node] = 1;
	if (!node) return; // No root
	pre_nodes.pb(node);
	DFS(A[node]);
	DFS(B[node]);
	post_nodes.pb(node);
}

int main () {
	// #ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	// #endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	for (int z=1; z<=T; z++) {
		cin >> N >> K;
		pre_nodes.clear();
		post_nodes.clear();
		memset(vis, 0, sizeof(vis));
		mii labels; // Store labels
		int cnt = 0;
		Disjoint ds(MAXN);
		ds.make_Set();
		for (int i=1; i<=N; i++) cin >> A[i] >> B[i];
		DFS(1);
		for (size_t i=0; i<pre_nodes.size(); i++) if (ds.Merge(pre_nodes[i], post_nodes[i])) ds.Union(pre_nodes[i], post_nodes[i]);
		for (int i=1; i<=N; i++) {
			if (!labels.count(ds.Find(i))) {
				if (cnt < K) labels[ds.Find(i)] = ++cnt;
				else labels[ds.Find(i)] = K;
			}
		}
		cout << "Case #" << z << ": ";
		if (cnt < K) cout << "Impossible" << "\n";
		else {
			for (int i=1; i<=N; i++) cout << labels[ds.Find(i)] << " ";
			cout << "\n";
		}
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