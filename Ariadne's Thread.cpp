#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define SIZE 320
#define MAXN 100010
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

void LCA_DFS (int idx, int node, int prev);
int LCA (int x, int y);

int N, C, a, Q, u, v, cnt, res, DFN[MAXN], depth[MAXN], par[MAXN], top[MAXN];
vi adj[MAXN];
si occ[MAXN];

int main () {
    scan(N);
    for (int i=1; i<=N; i++) {
        scan(C);
        for (int j=0; j<C; j++) {
            scan(a);
            adj[i].pb(a);
        }
    }
    LCA_DFS(0, 1, -1);
    scan(Q);
    for (int i=0; i<Q; i++) {
        scan(u); scan(v);
        if (u == v) {
            printf("%d\n", 0);
            continue;
        }
        int lca = LCA(u, v);
      // Case 1: (u is visited before v)
        if (DFN[u] < DFN[v]) printf("%d\n", DFN[v] - DFN[lca] - depth[u] + depth[lca]);
      // Case 2: Get size of subtree
        else {
            auto it = occ[lca].lower_bound(DFN[u]);
            // Leaf node
            if (*it == DFN[u]) res = 0;
            else res = abs(*it - *(--it));
            printf("%d\n", DFN[v] - DFN[lca] - depth[u] + depth[lca] + res);
        }
    }
    return 0;
}

// Calculate the depths of each node in the tree
void LCA_DFS (int idx, int node, int prev) {
    depth[node] = idx;
    par[node] = prev;
    DFN[node] = cnt;
    if (!(idx % SIZE)) top[node] = par[node];
    else top[node] = top[prev];
    occ[node].insert(cnt++);
    for (int next : adj[node]) {
        if (next == prev) continue;
        LCA_DFS(idx + 1, next, node);
        occ[node].insert(cnt++);
    }
}

// Calculate the LCA of two nodes
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