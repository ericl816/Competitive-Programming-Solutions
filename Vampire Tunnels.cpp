#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXX 1610
#define MAXY 3610
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

struct Edge {
    int node, dist, light;
};

int S, N, E, s, t, d, u;
ll ans = INF;
int dist[MAXX][MAXY];
bool vis[MAXX][MAXY];
vector<vector<Edge> > vec;
queue<pii> q;

int main () {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> S >> N >> E;
  vec = vector<vector<Edge> >(N + 1);
  for (int i=0; i<E; i++) {
    cin >> s >> t >> d >> u;
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
    for (size_t i=0; i<vec[idx].size(); i++) {
      Edge &next = vec[idx][i];
      int light = (next.light ? next.dist : 0);
      if (cost + light > S) continue;
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
  cout << (ans == INF ? -1 : ans) << "\n";
  return 0;
}