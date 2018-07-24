#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXN 20010
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

int N, a, b;
vi ans;
vi adj[MAXN];
int subtree_size[MAXN], centroid_score[MAXN];
bool vis[MAXN];

inline void DFS (int node, int prev) {
	if (vis[node]) return;
	vis[node] = 1;
	subtree_size[node] = 1;
	centroid_score[node] = 0;
	for (size_t i=0; i<adj[node].size(); i++) {
		int &next = adj[node][i];
		if (next == prev) continue;
		DFS(next, node);
		subtree_size[node] += subtree_size[next];
		centroid_score[node] = max(centroid_score[node], subtree_size[next]);
	}
	centroid_score[node] = max(centroid_score[node], N - subtree_size[node]);
}

int main () {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	scanf("%d", &N);
	for (int i=1; i<N; i++) {
		scanf("%d %d", &a, &b);
		adj[a].pb(b);
		adj[b].pb(a);
	}
	DFS(1, -1);
	int maxx_score = N + 1;
	for (int i=1; i<=N; i++) {
		if (centroid_score[i] < maxx_score) {
			maxx_score = centroid_score[i];
			ans.clear();
		}
		if (centroid_score[i] == maxx_score) ans.pb(i);
	}
	sort(ans.begin(), ans.end());
	printf("%d %d\n", maxx_score, ans.size());
	for (auto next : ans) printf("%d ", next);
	printf("\n");
	return 0;
}