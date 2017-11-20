#include <bits/stdc++.h>
#define ll long long
#define SIZE 230
#define MAXM 50010
#define MAXN 100010
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
#define si set<int>
#define usi unordered_set<int>
using namespace std;

struct Disjoint {
private:
    int N;
    vi lead, rank;

public:
    Disjoint (int N) : N(N), lead(N + 1), rank(N + 1) { }

    void make_Set () {
        for (int i=1; i<=N; i++) lead[i] = i;
    }

    int Find (int n) {
        while (lead[n] ^ n) {
            lead[n] = lead[lead[n]];
            n = lead[n];
        }
        return n;
    }

    bool Merge (int x, int y) {
        if (Find(x) ^ Find(y)) return Find(x) ^ Find(y);
        return 0;
    }

    void Union (int x, int y) {
        int a = Find(x);
        int b = Find(y);
        if (Merge(a, b)) {
            if (rank[a] > rank[b]) {
                lead[b] = a;
                rank[a] += rank[b];
            }
            else {
                lead[a] = b;
                rank[b] += a;
            }
        }
    }
};

struct Edge {
    int a, b, c;
    bool operator < (const Edge &a) const {
    return c < a.c;
  }
};

void LCA_DFS (int idx, int node, int prev, int weight);
int LCA (int x, int y);
int Max_Edge (int x, int y);

int N, M, a, b, c, idx, heaviestedge, res;
int depth[MAXM], par[MAXM], top[MAXM], maxedge[MAXM], maxedge1[MAXM];
ll cheapest = INF, totalcost;
vector<Edge> edgelist, unused;
vector<pii> MST[MAXN];
Disjoint ds (MAXM);
bool flag;

int main () {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    ds.make_Set();
    if (M < N - 1) {
        cout << -1 << "\n";
        return 0;
    }
    for (int i=0; i<M; i++) {
        cin >> a >> b >> c;
        edgelist.pb((Edge) {a, b, c});
    }
    sort(edgelist.begin(), edgelist.end());
    for (Edge &next : edgelist) {
        int store1 = next.a;
        int store2 = next.b;
        int cost1 = next.c;
        // Do Kruskal
        if (ds.Merge(store1, store2)) {
            ds.Union(store1, store2);
            MST[store1].pb(mp(store2, cost1));
            MST[store2].pb(mp(store1, cost1));
            totalcost += cost1;
        }
        else unused.pb(next);
    }
    // If all edges were used
    if (unused.empty()) {
        cout << -1 << "\n";
        return 0;
    }
    LCA_DFS(0, 1, -1, 0);
    for (Edge &next1 : unused) {
        int lca = LCA(next1.a, next1.b);
        heaviestedge = max(Max_Edge(next1.a, lca), Max_Edge(next1.b, lca));
        if (heaviestedge < next1.c) cheapest = min(cheapest, totalcost + next1.c - heaviestedge);
    }
    cout << (cheapest == INF ? -1 : cheapest) << "\n";
}

void LCA_DFS (int idx, int node, int prev, int weight) {
    depth[node] = idx;
    par[node] = prev;
    maxedge[node] = weight; 
    if (idx <= SIZE) {
        top[node] = prev;
        maxedge1[node] = weight;
    }
    else {
        top[node] = top[prev];
        maxedge1[node] = max(maxedge1[prev], weight);
    }
    for (size_t i=0; i<MST[node].size(); i++) {
        pii &next = MST[node][i];
        int currnode = next.f;
        int cost = next.s;
        if(currnode == prev) continue;
        LCA_DFS(idx + 1, currnode, node, cost);
    }
}

int LCA (int x, int y) {
    while (top[x] ^ top[y]) {
        if (depth[x] < depth[y]) swap(x, y);
        x = top[x];
    }
    while (x ^ y) {
        if (depth[x] < depth[y]) swap(x, y);
        x = par[x];
    }
    return x;
}

int Max_Edge (int x, int y) {
    while (depth[y] <= depth[top[x]] && ~top[x]) {
        res = max(res, maxedge1[x]);
        x = top[x];
    }
    while (x ^ y) {
        res = max(res, maxedge[x]);
        x = par[x];
    }
    return res;
}