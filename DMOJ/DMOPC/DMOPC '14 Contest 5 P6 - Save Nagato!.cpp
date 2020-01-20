#include <bits/stdc++.h>
#define ll long long
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define MAXN 500010
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

int N, u, v;
vi adj[MAXN];
int max1[MAXN], max2[MAXN], child[MAXN], DP[MAXN];

inline void DFS (int node, int prev) {
    for (size_t i=0; i<adj[node].size(); i++) {
        int &next = adj[node][i];
        if (next == prev) continue;
        DFS(next, node);
        if (max1[node] < max1[next] + 1) {
            max2[node] = max1[node];
            max1[node] = max1[next] + 1;
            child[node] = next;
        }
        else if (max2[node] < max1[next] + 1) max2[node] = max1[next] + 1;
    }
}

inline void Recur (int minn, int node, int prev) {
    DP[node] = max(minn, max1[node]);
    for (size_t i=0; i<adj[node].size(); i++) {
        int &next = adj[node][i];
        if (next == prev) continue;
        if (next == child[node]) Recur(max(minn + 1, max2[node] + 1), next, node);
        else Recur(max(minn + 1, max1[node] + 1), next, node);
    }
}

int main() {
    scan(N);
    for (int i=0; i<N-1; i++) {
        scan(u); scan(v);
        adj[--u].pb(--v);
        adj[v].pb(u);
    }
    DFS(0, -1);
    Recur(0, 0, -1);
    for (int i=0; i<N; i++) printf("%d\n", DP[i] + 1);
    return 0;
}