#include <bits/stdc++.h>
#define ll long long
#define MAXM 200010
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

int N, R, a, b, r, X, Y, ans = INF;
int dist[MAXM];
bool vis[MAXM], bunnies[MAXM], path[MAXM];
vi adj[MAXM];
queue<int> q;

void MarkPath (int node, int par) {
  if (node == Y) path[node] = 1;
  for (size_t i=0; i<adj[node].size(); i++) {
    int &next = adj[node][i];
    if (next == par) continue;
    MarkPath(next, node);
    path[node] |= path[next];
  }
}

void DFS (int node, int par) {
  if (bunnies[node] || vis[node]) dist[node] = 0;
  vis[node] = 1;
  for (size_t i=0; i<adj[node].size(); i++) {
    int &next = adj[node][i];
    if (next == par) continue;
    if (!vis[next]) DFS(next, node);
    dist[node] = min(dist[node], dist[next] + 1);
  }
  if (path[node]) ans = min(ans, dist[node]);
}

int main () {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> R;
    for (int i=0; i<N - 1; i++) {
        cin >> a >> b;
        a--; b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    for (int i=0; i<R; i++) {
        cin >> r;
        r--;
        bunnies[r] = 1;
    }
    cin >> X >> Y;
    X--; Y--;
    memset(vis, 0, sizeof(vis));
    memset(dist, INF, sizeof(dist));
    MarkPath(X, -1);
    DFS(X, -1);
    cout << ans << endl;
    return 0;
}