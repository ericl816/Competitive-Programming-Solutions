// http://codeforces.com/blog/entry/59281
#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXM 1010
#define MAXN 200010
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

/* 
 * Solution is simple: 
 * A component is cyclic if the degree of each vertex in the component is equal to 2
 * This can be done with a simple DFS
 */

int n, m, ans;
int indeg[MAXN];
bool flag = 1;
bool vis[MAXN];
vi conn;
vi adj[MAXN];

inline void DFS (int node, int prev) {
    if (vis[node]) return;
    vis[node] = 1;
    conn.pb(node);
    for (size_t i=0; i<adj[node].size(); i++) {
        int &next = adj[node][i];
        if (next == prev) continue;
        if (!vis[next]) DFS(next, node);
    }
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i=0, x, y; i<m; ++i) {
        cin >> x >> y;
        --x, --y;
        adj[x].pb(y);
        adj[y].pb(x);
        ++indeg[x];
        ++indeg[y];
    }
    for (int i=0; i<n; ++i) {
        if (!vis[i]) {
            conn.clear();
            DFS(i, -1);
            flag = 1;
            for (auto v : conn) flag &= indeg[v] == 2;
            ans += flag;
        }
    }
    cout << ans << "\n";
    return 0;
}