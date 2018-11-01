#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define ull unsigned long long
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
#define DEBUG 1
#ifdef DEBUG
    #define D(x...) printf(x)
#else
    #define D(x...)
#endif
using namespace std;

int N, M, root, x, y, cnt, maxx;
bool isPho[MAXN], vis[MAXN];
vi adj[MAXN], path[MAXN];
int dist[MAXN];

inline void DFS1 (int node, int prev) {
    if (vis[node]) return;
    vis[node] = 1;
    if (dist[node] > maxx && isPho[node]) {
        maxx = dist[node];
        root = node;
    }
    for (size_t i=0; i<adj[node].size(); i++) {
        int &next = adj[node][i];
        if (next == prev) continue;
        dist[next] = dist[node] + 1;
        DFS1(next, node);
        if (isPho[next] || path[next].size()) {
            path[node].pb(next);
            path[next].pb(node);
            ++cnt;
        }
    }
    vis[node] = 0;
}

inline void DFS2 (int node, int prev) {
    if (vis[node]) return;
    vis[node] = 1;
    if (dist[node] > maxx) {
        maxx = dist[node];
        root = node;
    }
    for (size_t i=0; i<path[node].size(); i++) {
        int &next = path[node][i];
        if (next == prev) continue;
        dist[next] = dist[node] + 1;
        DFS2(next, node);
    }
}

int main (int argc, char const *argv[]) {
    #ifdef NOT_DMOJ
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif // NOT_DMOJ
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    while (M--) {
        cin >> root;
        isPho[root] = 1;
    }
    for (int i=1; i<N; i++) {
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    DFS1(root, -1);
    dist[root] = 0;
    maxx = 0;
    DFS2(root, -1);
    cout << ((cnt << 1) - maxx) << "\n";
    return 0;
}

/* 
 * Look for:
 * the exact constraints (multiple sets are too slow for n=10^6 :( ) 
 * special cases (n=1?)
 * overflow (ll vs int?)
 * array bounds
 */