#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXN 210
#define min(a, b) (a) < (b) ? (a) : (b)
#define max(a, b) (a) < (b) ? (b) : (a)
#define INF 0x3f3f3f3f
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define pdd pair<double, double>
#define mp make_pair
#define f first
#define s second
#define mii map<int, int>
#define umii unordered_map<int, int>
#define infiniteDistance 1e18
#define infiniteFlow 1e18
#define EPS 1e-7
#define Cost double
#define Flow ll
using namespace std;

int N;
pii loc[MAXN];
pdd ans;

struct MinCostMaxFlow {
    struct Edge {
        int u, v;
        Flow f, c;
        Cost w;
        Edge (int u, int v, Flow f, Flow c, Cost w) : u(u), v(v), f(f), c(c), w(w) { }
    };
    vector<Edge> e;
    vector<vi> g;
    int n, source, sink, *prev;
    Cost *dist;
    
    MinCostMaxFlow (int n) : n (n) {
        dist = (Cost*)malloc(sizeof(Cost) * n);
        prev = (int*) malloc(sizeof(int) * n);
        g.resize(n);
    }
    
    ~MinCostMaxFlow () {
        free(dist);
        free(prev);
        g.clear();
    }
    
    inline void Add_Edge (int u, int v, Flow c, Cost w){
        g[u].pb(e.size());
        e.pb(Edge(u, v, 0, c, w));
        g[v].pb(e.size());
        e.pb(Edge(v, u, 0, 0, -w));
    }
    
    inline pair<Cost, Flow> getMaxFlow (int source, int sink) {
        this->source = source;
        this->sink = sink;
        for (int i=0; i<(int) e.size(); i++) e[i].f = 0;
        Flow flow = 0;
        Cost cost = 0;
        while (BellmanFord()) {
            int u = sink;
            Flow pushed = infiniteFlow;
            Cost pushCost = 0;
            while (u ^ source) {
                int id = prev[u];
                pushed = min(pushed, e[id].c - e[id].f);
                pushCost += e[id].w;
                u = e[id].u;
            }
            u = sink;
            while (u ^ source) {
                int id = prev[u];
                e[id].f += pushed;
                e[id ^ 1].f -= pushed;
                u = e[id].u;
            }
            flow += pushed;
            cost += pushCost * pushed;
        }
        return mp(cost, flow);
    }
    
    inline bool BellmanFord () {
        for (int i=0; i<n; i++) dist[i] = infiniteDistance;
        dist[source] = 0;
        for (int k=0; k<n; k++) {
            bool update = 0;
            for(int id=0; id<(int) e.size(); id++) {
                int u = e[id].u;
                int v = e[id].v;
                if (dist[u] + EPS >= infiniteDistance) continue;
                Cost w = e[id].w;
                if (e[id].f < e[id].c && dist[v] > dist[u] + w + EPS) {
                    dist[v] = dist[u] + w;
                    prev[v] = id;
                    update = 1;
                }
            }
            if (!update) break;
        }
        return (dist[sink] + EPS) < (infiniteDistance);
    }
    
    inline void PrintFlowEdges () {
        for (size_t i=0; i<e.size(); i++) {
            Edge &ed = e[i];
            cout << ed.u << " " << ed.v - N << "\n";
        }
    }
};

MinCostMaxFlow flow(MAXN);

int main () {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i=1; i<=2 * N; i++) cin >> loc[i].f >> loc[i].s;
    for (int i=1; i<=N; i++){
        flow.Add_Edge(0, i, 1, 0);
        flow.Add_Edge(i + N, 2 * N + 1, 1, 0);
        for (int j=1; j<=N; j++) flow.Add_Edge(i, j + N, 1, sqrt(pow(loc[i].f - loc[j + N].f, 2) + pow(loc[i].s - loc[j + N].s, 2)));
    }
    ans = flow.getMaxFlow(0,2 * N + 1);
    flow.PrintFlowEdges();
    return 0;
}