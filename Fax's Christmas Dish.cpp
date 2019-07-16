#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXN 300010
#define INF 0x3f3f3f3f3f3f
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

int N, M, D, targ, req, a, days, ans;
vi adj[MAXN];
bool vis[MAXN], leaf[MAXN];

inline void DFS (int node, int prev) {
    if (vis[node]) return;
    vis[node] = 1;
    if (!leaf[node]) ans--;
    for (size_t i=0; i<adj[node].size(); i++) {
        int &next = adj[node][i];
        if (next == prev) continue;
        DFS(next, node);
    }
}

int main () {
    scan(N); scan(M); scan(D);
    ans = N - M;
    for (int i=0; i<M; i++) {
        scan(targ); scan(req);
        leaf[targ] = 1;
        for (int j=0; j<req; j++) {
            scan(a);
            adj[targ].pb(a);
        }
    }
    for (int i=1; i<=D; i++) {
        scan(days);
        DFS(days, -1);
        if (ans == 0) return 0 * printf("%d\n", i);
    }
    printf("%d\n", -1);
    return 0;
}