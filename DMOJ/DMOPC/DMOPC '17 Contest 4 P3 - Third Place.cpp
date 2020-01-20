#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXN 100010
#define INF 0x3f3f3f3f
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
using namespace std;

int N, a, b, c;
ll longest = -1, ans = -1, node, prevnode;
vector<pii> adj[MAXN]; 
ll dist[MAXN];
queue<int> q;
bool vis[MAXN];

inline void BFS (int src) {
  memset(dist, INF, sizeof(dist));
  memset(vis, 0, sizeof(vis));
  vis[src] = 1;
  dist[src] = 0;
  q.push(src);
  while (!q.empty()) {
    int curr = q.front();
    q.pop();
    for (size_t i=0; i<adj[curr].size(); i++) {
      pii &next = adj[curr][i];
      if (!vis[next.f]) {
        vis[next.f] = 1;
        dist[next.f] = dist[curr] + next.s;
        q.push(next.f);
      }
    }
  }
}

int main () {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i=1; i<N; i++) {
      cin >> a >> b >> c;
      a--; b--;
      adj[a].pb(mp(b, c));
      adj[b].pb(mp(a, c));
    }
    BFS(0);
    for (int i=0; i<N; i++) {
      if (dist[i] > longest) {
        longest = dist[i];
        node = i;
      }
    }
    BFS(node);
    prevnode = node;
    longest = -1;
    for (int i=0; i<N; i++) {
      if (dist[i] >= longest) {
        ans = longest;
        longest = dist[i];
        node = i;
      }
      else if (dist[i] > ans) ans = dist[i];
    }
    BFS(node);
    for (int i=0; i<N; i++) {
      if (dist[i] >= longest && i ^ prevnode) {
        ans = longest;
        longest = dist[i];
      }
      else if (dist[i] > ans && i ^ prevnode) ans = dist[i];
    }
    cout << ans << endl;
    return 0;
}