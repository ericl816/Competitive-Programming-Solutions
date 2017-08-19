#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define INF 0x3f3f3f3f
#define MAXX 1601
#define MAXY 3601
#define min(a, b) (a) < (b) ? (a) : (b)
#define pii pair<int, int>
#define mp make_pair
#define pb push_back
#define p push
#define f first
#define s second
using namespace std;

struct Edge {
    int node, dist, light;
};

int S, N, E, s, t, d, u, ans = INF, dist[MAXX][MAXY];
bool vis[MAXX][MAXY];
vector<vector<Edge>>vec;
queue<pii> q;

int main() {
    scan(S);
    scan(N);
    scan(E);
    vec = vector<vector<Edge>>(N + 1);
    for (int i=0; i<E; i++) {
        scan(s);
        scan(t);
        scan(d);
        scan(u);
        vec[s].pb((Edge) {t, d, u});
        vec[t].pb((Edge) {s, d, u});
    }
    memset(dist, INF, sizeof(dist));
    dist[0][0] = 0;
    vis[0][0] = 1;
    q.push(mp(0, 0));
    while (!q.empty()) {
      pii curr = q.front(); 
      q.pop();
      int idx = curr.f;
      int cost = curr.s;
      vis[idx][cost] = 0;
      for (Edge next : vec[idx]) {
        int light = (next.light ? next.dist : 0);
        if (light + cost > S) continue;
        int nextcost = dist[idx][cost] + next.dist;
        if (dist[next.node][light + cost] > nextcost) {
        dist[next.node][light + cost] = nextcost;
          if (!vis[next.node][light + cost]) {
            vis[next.node][light + cost] = 1;
            q.push(mp(next.node, light + cost));
          }
        }
      }
    }
    for (int i=0; i<=S; i++) ans = min(ans, dist[N - 1][i]);
    printf("%d\n", (ans == INF ? -1 : ans));
}
