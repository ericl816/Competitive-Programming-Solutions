#include <bits/stdc++.h>
#define ll long long
#define MAXN 100010
#define INF 0x3f3f3f3f
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define pid pair<int, double>
#define pdi pair<double, int>
#define mp make_pair
#define f first
#define s second
using namespace std;

vector<pid> adj[MAXN];
int N, M, a, b, c, num[MAXN];
double dist[MAXN];
bool vis[MAXN], safe, flag;
queue<int> q;

void SSSP(int src) {
    fill(dist, dist + N, INF);
    fill(vis, vis + N, 0);
    dist[src] = 0.0;
    q.push(src);
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        for (pid &next : adj[curr]) {
            int node = next.f;
            double cost = next.s; 
            double nextcost = dist[curr] + cost;
            if (dist[node] > nextcost) {
                dist[node] = nextcost;
                num[node] = num[curr] + 1;
                q.push(node);
            }
        }
    }
}

int main() {
    scanf("%d", &N);
    scanf("%d", &M);
    for (int i=0; i<M; i++) {
        scanf("%d", &a);
        scanf("%d", &b);
        scanf("%d", &c);
        a--; b--;
        safe = c;
        adj[a].pb(mp(b, safe ? 1 : 1e-5));
        adj[b].pb(mp(a, safe ? 1 : 1e-5));
    }
    SSSP(0);
    flag = (dist[N - 1] == INF);
    if (flag) return 0 * printf("%d\n", -1);
    else printf("%d %d\n", (int) floor(dist[N - 1]), num[N - 1]);
    return 0;
}