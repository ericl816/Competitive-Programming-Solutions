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
vi ids[MAXN];
ll sum;
vector<ll> ans;

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
			ids[i].pb(i);
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
			if (ids[a].size() > ids[b].size()) swap(a, b);
			for (auto i : ids[a]) {
				sum += cnt[b][XOR[i]];
			}
			for (auto i : ids[a]) {
				cnt[b][XOR[i]]++;
				ids[b].pb(i);
			}
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
};

Disjoint ds(MAXN);

inline void DFS (int node, int prev, int val) {
	if (vis[node]) return;
	vis[node] = 1;
	XOR[node] = val;
	for (size_t i=0; i<adj[node].size(); i++) {
		pii &next = adj[node][i];
		if (next.f == prev) continue;
		DFS(next.f, node, val ^ next.s);
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
    DFS(0, -1, 0);
    for (int i=0, x; i<N - 1; i++) {
    	cin >> x;
    	order.pb(--x);
    }
    reverse(order.begin(), order.end());
    ds.make_Set();
    for (size_t i=0; i<order.size(); i++) {
    	int &next = order[i];
    	if (ds.Merge(A[next], B[next])) {
    		ds.Union(A[next], B[next]);
    		ans.pb(sum);
    	}
    }
    reverse(ans.begin(), ans.end());
    ans.pb(0);
    for (auto i : ans) cout << i << "\n";
    return 0;
}