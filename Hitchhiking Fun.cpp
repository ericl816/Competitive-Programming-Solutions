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
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
    for (int i=0; i<M; i++) {
        cin >> a >> b >> c;
        a--; b--;
        safe = c;
        // If it's not safe, make sure the weight is negligible
        adj[a].pb(mp(b, safe ? 1 : 1e-5));
        adj[b].pb(mp(a, safe ? 1 : 1e-5));
    }
    SSSP(0);
    flag = (dist[N - 1] == INF);
    if (flag) {
    	cout << -1 << "\n";
    	return 0;
    }
    else cout << (int) floor(dist[N - 1]) << " " << (num[N - 1]) << "\n";
}
