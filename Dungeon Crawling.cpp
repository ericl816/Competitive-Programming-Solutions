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
ll num, num1[MAXN];
vi adj[MAXN];
bool vis[MAXN], a1[MAXN], b1[MAXN];
queue<int> q;

void DFS (int node, int par) {
  vis[node] = 1;
  for (int i=0; i<N; i++) {
    if (node == par || vis[i]) continue;
    DFS(i, i);
    if (b1[i]) num = (num + num1[i]) % MOD;
  }
}

inline void BFS () {
    for (int i=0; i<N; i++) {
        if (a1[i]) {
            num1[i] = 1;
            q.push(i);
            dist[i] = 0;
        }
    }
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
			num1[next] = (num1[next] + num1[curr]) % MOD;
		}
	}
}

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	memset(a1, 1, sizeof(a1));
	memset(b1, 1, sizeof(b1));
	memset(dist, INF, sizeof(dist));
	for (int i=0; i<M; i++) {
		cin >> a >> b;
		adj[a].pb(b);
		b1[a] = 0;
		a1[b] = 0;
	}
	BFS();
	DFS(0, -1);
	cout << (num % MOD) << "\n";
	for (int i=0; i<N; i++) if (b1[i]) cout << (dist[i] + 1) << " ";
	cout << "\n";
	return 0;
}