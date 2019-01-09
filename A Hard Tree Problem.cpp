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
#define vi vector<int>
#define vll vector<ll>
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

inline int GCD (int a, int b) { return b == 0 ? a : GCD(b, a % b); }
inline int LCM (int a, int b) { return a * b / GCD(a, b); }
inline ll PowMod (ll a, ll b, ll MOD) { ll val = 1; while (b) { if (b & 1) val = (val * a) % MOD; a = (a * a) % MOD; b >>= 1; } return val; }

int N, a, b, node = INF, maxx = -INF;
vi adj[MAXN];
bool vis[MAXN];
ll depth[MAXN];

inline void DFS (int node, int prev, int len) {
    if (vis[node]) return;
    vis[node] = 1;
    depth[node] = len;
    for (auto i : adj[node]) {
        if (i == prev) continue;
        DFS(i, node, len + 1);
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
    cin >> N;
    for (int i=1; i<N; i++) {
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    DFS(1, -1, 0);
    for (int i=1; i<=N; i++) {
        if (depth[i] > maxx) {
            maxx = depth[i];
            node = i;
        }
        else if (depth[i] == maxx) {
            node = min(node, i);
        }
    }
    memset(vis, 0, sizeof(vis));
    DFS(node, -1, 0);
    maxx = -INF;
    for (int i=1; i<=N; i++) {
        if (depth[i] > maxx) {
            maxx = depth[i];
        }
    }
    for (int i=1; i<=N; i++) {
        if (depth[i] == maxx) {
            node = min(node, i);
        }
    }
    cout << maxx << " " << node << "\n";
    return 0;
}
/* 
 * Look for:
 * the exact constraints (multiple sets are too slow for n=10^6 :( ) 
 * special cases (n=1?)
 * overflow (ll vs int?)
 * array bounds
 */