#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXM 100010
#define MAXN 10010
#define INF 0x3f3f3f3f
#define MOD 1000000000LL
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

int N, M, A, B;
int indeg[MAXN];
ll subtree_size[MAXN];
vi adj[MAXN];
vi nodes;
bool flag;
bool vis[MAXN];
queue<int> q;

inline void DFS (int node, int par) {
	if (vis[node]) return;
	vis[node] = 1;
	for (size_t i=0; i<adj[node].size(); i++) {
		int &next = adj[node][i];
		if (vis[next]) continue;
		DFS(next, node);
	}
}

int main () {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	scan(N); scan(M);
	for (int i=0; i<M; i++) {
		scan(A); scan(B);
		adj[A].pb(B);
		++indeg[B];
	}
	DFS(1, -1);
	for (int i=1; i<=N; i++) {
		if (!vis[i]) {
			for (size_t j=0; j<adj[i].size(); j++) {
				int &next = adj[i][j];
				--indeg[next];
			}
		}
	}
	q.push(1);
	memset(vis, 0, sizeof(vis));
	while (!q.empty()) {
		int curr = q.front();
		q.pop();
		nodes.pb(curr);
		for (size_t i=0; i<adj[curr].size(); i++) {
			int &next = adj[curr][i];
			if (--indeg[next] == 0) q.push(next);
		}
	}
	subtree_size[1] = 1LL;
	for (size_t i=0; i<nodes.size(); i++) {
		int &node = nodes[i];
		for (size_t j=0; j<adj[node].size(); j++) {
			int &next = adj[node][j];
			subtree_size[next] += subtree_size[node];
			if (subtree_size[next] >= MOD) {
				flag = 1;
				subtree_size[next] %= MOD;
			}
		}
	}
	// for (int i=1; i<=N; i++) cout << subtree_size[i] << " ";
	if (flag) return !printf("%09lld\n", subtree_size[2] % MOD);
	return !printf("%lld\n", subtree_size[2]);
}