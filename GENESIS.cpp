#include <bits/stdc++.h>

#define min(a, b) ((a) > (b)) ? (b) : (a) 
#define MAXN 220
#define INF 0x3f3f3f3f
using namespace std;

int N, E, M, i, j, source, sink, amount, flow, maxflow;
int dist[MAXN], arr[MAXN], res[MAXN];
int graph[MAXN][MAXN];
vector<pair<int, int>> vec[MAXN];
queue<pair<int, int>> q;

inline bool hasPath () {
    memset(dist, -1, sizeof(dist));
    dist[source] = source;
    q.push(make_pair(source, source));
    while (!q.empty()) {
        pair<int, int> currnode = q.front(); 
        q.pop();
        if (currnode.first ^ sink && arr[currnode.first] <= res[currnode.first]) continue;
        for (pair<int, int> e : vec[currnode.first]) {
            if (0 > dist[e.first] && e.second > graph[currnode.first][e.first]) {
                dist[e.first] = currnode.second + 1;
                q.push(make_pair(e.first, dist[e.first]));
            }
        }
    }
      return dist[sink] ^ -1;
}

inline int IncreaseResFlow(int node, int minedge) {
    if (node == sink) return minedge;
    for (pair<int, int> e : vec[node]) {
        if (dist[e.first] == dist[node] + 1 && e.second > graph[node][e.first]) {
          amount = IncreaseResFlow(e.first, min(arr[node] - res[node], min(minedge, e.second - graph[node][e.first])));
            if (amount > 0) {
                graph[node][e.first] += amount;
                graph[e.first][node] -= amount;
                res[node] += amount;
                return amount;
            }
        }
    }
    return 0;
}

inline void GetFlow () {
  while(hasPath()) {
    flow = IncreaseResFlow(0, INF);
    if (flow <= 0) break;
    maxflow += flow;
  }
}

int main() {
    scanf("%d", &N);
    sink = N - 1;
    for (int i=1; i<=N - 1; i++) {
        scanf("%d", &E);
        arr[i - 1] = E;
    }
    scanf("%d", &M);
    for (int a=1; a<=M; a++) {
        scanf("%d %d", &i, &j);
        i--; j--;
        vec[i].push_back(make_pair(j, INF));
    }
    GetFlow();
    printf("%d\n", maxflow);
    return 0;
}
