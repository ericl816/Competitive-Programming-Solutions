#include <bits/stdc++.h>
#define ll long long
#define MAXN 5010
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

int N, M, Q, A, B, X, Y, idx, cnt;
int low[MAXN], DFN[MAXN], par[MAXN], comp[MAXN], tot[MAXN];
int DP[MAXN][MAXN];
vi adj[MAXN];
bool processed[MAXN], vis[MAXN];
bool better[MAXN][MAXN];
stack<int> SCC;
set<int> DAG[MAXN];

inline void TarjansDFS (int node, int prev) {
	low[node] = DFN[node] = idx++;
	SCC.push(node);
	processed[node] = 1;
	for (size_t i=0; i<adj[node].size(); i++) {
		int &next = adj[node][i];
		if (next == prev) continue;
		if (!DFN[next]) {
			TarjansDFS(next, node);
			low[node] = min(low[node], low[next]);
		}
		else if (processed[next]) low[node] = min(low[node], DFN[next]);
	}
	if (low[node] == DFN[node]) {
		while (SCC.top() ^ node) {
			int curr = SCC.top();
			comp[curr] = cnt;
			tot[cnt]++;
			processed[curr] = 0;
			SCC.pop();
		}
		int curr = SCC.top();
		processed[curr] = 0;
		comp[curr] = cnt;
		tot[cnt]++;
		SCC.pop();
		cnt++;
	}
}

inline void Reconstruct_DAG () {
	for (int i=1; i<=N; i++) {
		for (size_t j=0; j<adj[i].size(); j++) {
			int &next = adj[i][j];
			if (comp[i] ^ comp[next]) DAG[comp[i]].insert(comp[next]);
		}
		adj[i].clear();
	}
}

// Method computes the MEV between two nodes
inline void Get_MEV (int node, int prev) {
	vis[node] = 1;
	for (size_t i=0; i<adj[node].size(); i++) {
		int &next = adj[node][i];
		if (next == prev) continue;
		if (!vis[next]) Get_MEV(next, node);
		if (comp[node] ^ comp[next] && !better[comp[node]][comp[next]]) {
			for (int j=0; j<cnt; j++) {
				better[comp[node]][j] |= better[comp[next]][j];
				if (better[comp[next]][j]) DP[comp[node]][j] = max(DP[comp[node]][j], DP[comp[next]][j] + tot[comp[next]]);
			}
			better[comp[node]][comp[next]] = 1;
		} 
	}
}

// Returns the better participant as well as the MEV value
inline pii Get_Better (int A, int B) {
	return better[comp[X]][comp[Y]] ? mp(X, DP[comp[X]][comp[Y]]) : mp(Y, DP[comp[Y]][comp[X]]);
}

int main () {
	scanf("%d %d %d", &N, &M, &Q);
	for (int i=0; i<M; i++) {
		scanf("%d %d", &A, &B);
		adj[A].pb(B);
	}
	for (int i=1; i<=N; i++) if (!DFN[i]) TarjansDFS(i, -1);
	for (int i=1; i<=N; i++) if (!vis[i]) Get_MEV(i, -1);
	// Reconstruct_DAG();
	for (int i=0; i<Q; i++) {
		scanf("%d %d", &X, &Y);
		if (comp[X] == comp[Y]) printf("%s\n", "Indeterminate");
		else {
			// Participant X is better than Y
			if (better[comp[X]][comp[Y]]) printf("%d %d\n", X, DP[comp[X]][comp[Y]]);
			// Participant Y is better than X
			else if (better[comp[Y]][comp[X]]) printf("%d %d\n", Y, DP[comp[Y]][comp[X]]);
			else printf("%s\n", "Indeterminate");
		}
	}
	return 0;
}