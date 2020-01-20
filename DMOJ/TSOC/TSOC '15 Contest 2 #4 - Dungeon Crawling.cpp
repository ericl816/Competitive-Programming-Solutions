#include <bits/stdc++.h>
#define ll long long
#define MAXN 20010
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define mii map<int, int>
#define umii unordered_map<int, int>
using namespace std;

int N, M, a, b, dist[MAXN];
ll num, cnt[MAXN];
vi adj[MAXN];
bool vis[MAXN], ent[MAXN], dest[MAXN];
queue<int> q;

inline void BFS () {
	while (!q.empty()) {
		int curr = q.front();
		q.pop();
		for (size_t i=0; i<adj[curr].size(); i++) {
			int &next = adj[curr][i];
			int nextcost = dist[curr] + 1;
			if (nextcost < dist[next]) {
				dist[next] = nextcost;
				q.push(next);
			}
			cnt[next] = (cnt[next] + cnt[curr]) % MOD;
		}
	}
}

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	memset(dist, INF, sizeof(dist));
	for (int i=0; i<M; i++) {
		cin >> a >> b;
		adj[a].pb(b);
		dest[a] = 1;
		ent[b] = 1;
	}
	for (int i=0; i<N; i++) {
		if (!ent[i]) {
			q.push(i);
			dist[i] = 0;
			cnt[i] = 1;
		}
	}
	BFS();
	for (int i=0; i<N; i++) if (!dest[i]) num = (num + cnt[i]) % MOD;
	cout << (num % MOD) << "\n";
	for (int i=0; i<N; i++) if (!dest[i]) cout << (dist[i] + 1) << " ";
	cout << "\n";
	return 0;
}