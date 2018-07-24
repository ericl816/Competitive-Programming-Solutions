#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define MAXN 1010
#define INF 0x3f3f3f3f
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define umii unordered_map<int, int>
#define mii map<int, int>
using namespace std;

struct Disjoint {
private:
	int N;
	vi lead, rank;

public:
	Disjoint (int N) : N(N), lead(N + 1), rank(N + 1) { }

	void make_Set () {
		for (int i=1; i<=N; i++) lead[i] = i, rank[i] = 1;
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
		if (a ^ b) {
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

int T = 5, N, M, x, y, cnt, ans, idx;
int DFN[MAXN], low[MAXN], par[MAXN];
Disjoint ds(MAXN);

// Use Tarjan's DFS to find the number of bridges in the graph
inline int TarjansDFS (vi adj[], int node, int prev) {
	DFN[node] = low[node] = idx++;
	for (size_t i=0; i<adj[node].size(); i++) {
		int &next = adj[node][i];
		if (next == prev) continue;
		if (!DFN[next]) {
			par[next] = node;
			TarjansDFS(adj, next, node);
			low[node] = min(low[node], low[next]);
			if (DFN[next] == low[next]) cnt++;
		}
		else if (par[node] ^ next) low[node] = min(low[node], DFN[next]); 
	}
	return cnt;
}

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	while (T--) {
		ds.make_Set();
		cnt = 0;
		idx = 1;
		memset(DFN, 0, sizeof(DFN));
		memset(low, 0, sizeof(low));
		memset(par, 0, sizeof(par));
		cin >> N >> M;
		vi adj[N + 1];
		for (int i=0; i<M; i++) {
			cin >> x >> y;
			x--; y--;
			adj[x].pb(y);
			adj[y].pb(x);
		}
		cout << TarjansDFS(adj, 0, -1) << endl;
	}
	return 0;
}