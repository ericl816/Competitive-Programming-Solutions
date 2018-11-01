#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define ull unsigned long long
#define MAXM 13
#define MAXN 6010
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
#ifdef DEBUG
    #define D(x...) printf(x)
#else
    #define D(x...)
#endif
using namespace std;

int N, a, b, w, Q, u, v;
int depth[MAXN];
int par[MAXN][MAXM];
ll dist[MAXN];
vector<pii> adj[MAXN];

inline void DFS (int node, int prev, ll weight) {
    dist[node] = weight;
    par[node][0] = prev;
    if (~prev) depth[node] = depth[prev] + 1;
    for (int i=1; i<MAXM; i++) {
        if (~par[node][i - 1]) par[node][i] = par[par[node][i - 1]][i - 1];
    }
    for (size_t i=0; i<adj[node].size(); i++) {
        pii &next = adj[node][i];
        if (next.f == prev) continue;
        DFS(next.f, node, next.s + weight);
    }
}

inline int LCA (int x, int y) {
    if (depth[x] < depth[y]) swap(x, y);
    for (int i=MAXM - 1; i>=0; i--) {
        if (~par[x][i] && depth[par[x][i]] >= depth[y]) x = par[x][i];
    }
    if (x == y) return x;
    for (int i=MAXM - 1; i>=0; i--) {
        if (par[x][i] ^ par[y][i]) {
            x = par[x][i];
            y = par[y][i];
        }
    }
    return par[x][0];
}

int main (int argc, char const *argv[]) {
    #ifdef NOT_DMOJ
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif // NOT_DMOJ
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    memset(par, -1, sizeof(par));
    for (int i=1; i<N; i++) {
        cin >> a >> b >> w;
        adj[a].pb(mp(b, w));
        adj[b].pb(mp(a, w));
    }
    DFS(1, -1, 0);
    cin >> Q;
    while (Q--) {
        cin >> u >> v;
        cout << dist[u] + dist[v] - (dist[LCA(u, v)] << 1) << "\n";
    }
    return 0;
}

/* 
 * Look for:
 * the exact constraints (multiple sets are too slow for n=10^6 :( ) 
 * special cases (n=1?)
 * overflow (ll vs int?)
 * array bounds
 */