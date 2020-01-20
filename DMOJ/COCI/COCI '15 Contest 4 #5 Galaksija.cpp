#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define INF 0x3f3f3f3f
#define MAXN 100010
#define MOD 1000000007
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

int N, Z;
vector<pii> adj[MAXN];
map<int, ll> cnt[MAXN];
int A[MAXN], B[MAXN], XOR[MAXN];
bool vis[MAXN];
vi order;
ll sum;
ll ans[MAXN];

struct Disjoint {
private:
	int N;
	vi lead, rank;

public:
	Disjoint (int N) : N(N), lead(N + 1), rank(N + 1) { }

	void make_Set () {
		for (int i=0; i<N; i++) {
			lead[i] = i;
			rank[i] = 0;
			cnt[i][XOR[i]] = 1LL;
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
		int a = Find(x);
		int b = Find(y);
		if (Merge(x, y)) {
			if (rank[a] > rank[b]) {
				lead[b] = a;
				rank[a] += rank[b];
			}
			else {
				lead[a] = b;
				rank[b] += rank[a];
			}
		}
	}
	
	int Size (int n) {
	    return rank[n];
	}
};

Disjoint ds(MAXN);

inline void DFS (int node, int prev) {
	if (vis[node]) return;
	vis[node] = 1;
	for (size_t i=0; i<adj[node].size(); i++) {
		pii &next = adj[node][i];
		if (next.f == prev) continue;
		XOR[next.f] = XOR[node] ^ next.s;
		DFS(next.f, node);
	}
}

int main () {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i=0; i<N - 1; i++) {
    	cin >> A[i] >> B[i] >> Z;
    	adj[--A[i]].pb(mp(--B[i], Z));
    	adj[B[i]].pb(mp(A[i], Z));
    }
    DFS(0, -1);
    for (int i=0, x; i<N - 1; i++) {
    	cin >> x;
    	order.pb(--x);
    }
    reverse(order.begin(), order.end());
    ds.make_Set();
    for (size_t i=0; i<order.size(); i++) {
    	int &next = order[i];
    	if (ds.Merge(A[next], B[next])) {
    		int id1 = ds.Find(A[next]), id2 = ds.Find(B[next]);
    		// cout << id1 << " " << id2 << "\n";
    		if (ds.Size(id2) > ds.Size(id1)) swap(id1, id2);
    		ds.Union(A[next], B[next]);
    		for (pair<int, ll> state : cnt[id2]) {
    			sum += cnt[id1][state.f] * state.s;
    			cnt[id1][state.f] += state.s;
    		}
    		ans[i] = sum;
    	}
    }
    for (int i=1; i<N; i++) cout << ans[N - i - 1] << "\n";
    cout << 0 << "\n";
    return 0;
}