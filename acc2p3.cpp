#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXN 1000010
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

// Use HLD to find SECOND heaviest edge in path from nodes a to b

struct Node {
    int l, r, val;
};

// Define variables needed for HLD
int depth[MAXN], par[MAXN], subtree_size[MAXN], head[MAXN], chain[MAXN], vert[MAXN], weight[MAXN], ind[MAXN];
int idx, chainNum;
int N, Q, a, b, c;
vector<pii> adj[MAXN];
pair<ll, ll> segmax[MAXN << 1];

inline pair<ll, ll> maxPair (const pair<ll, ll> &a, const pair<ll, ll> &b) {
    ll c[4] = {a.f, a.s, b.f, b.s};
    sort(c, c + 4);
    pair<ll, ll> res = mp(c[2], c[3]);
    return res;
}

inline void maxsegUpdate (int idx, int val) {
    idx += N - 1;
    segmax[idx] = mp(val, -INF);
    for (int i=idx >> 1; i; i >>= 1) segmax[i] = maxPair(segmax[i << 1], segmax[i << 1 | 1]);
}

inline pair<ll, ll> maxsegQuery (int l, int r, int idx = 1) {
    l += N - 1;
    r += N - 1;
    pair<ll, ll> maxans = mp(-INF, -INF);
    while (l <= r) {
        if (l & 1) {
            maxans = maxPair(maxans, segmax[l]);
            l++;
        }
        if (!(r & 1)) {
            maxans = maxPair(maxans, segmax[r]);
            r--;
        }
        l >>= 1;
        r >>= 1;
    }
    return maxans;
}

// HLD Code Portion!!!
/*********************************************************************************/

// @param val = depth of chain
inline void DFS (int node, int prev, int val) {
    depth[node] = val;
    par[node] = prev;
    subtree_size[node] = 1;
    for (size_t i=0; i<adj[node].size(); i++) {
        pii &next = adj[node][i];
        if (next.f == prev) continue;
        weight[next.f] = next.s;
        DFS(next.f, node, val + 1);
        subtree_size[node] += subtree_size[next.f];
    }
}

inline void HLD (int node, int prev) {
    if (head[chainNum] == -1) head[chainNum] = node;
    chain[node] = chainNum;
    ind[node] = idx;
    vert[idx++] = node;
    int maxidx = -1;
    for (size_t i=0; i<adj[node].size(); i++) {
        pii &next = adj[node][i];
        if (next.f == prev) continue;
        if (maxidx == -1 || subtree_size[maxidx] < subtree_size[next.f]) maxidx = next.f;
    }
    if (~maxidx) HLD(maxidx, node);
    for (size_t i=0; i<adj[node].size(); i++) {
        pii &next = adj[node][i];
        if (next.f == prev || next.f == maxidx) continue;
        chainNum++;
        HLD(next.f, node);
    }
}
    
inline void InitHLD () {
    chainNum = 0;
    idx = 1;
    memset(head, -1, sizeof(head));
    DFS(0, -1, 0);
    HLD(0, -1);
    for (int i=1; i<=N; i++) segmax[i + N - 1] = mp(weight[vert[i]], -INF);
    for (int i=N - 1; i>0; i--) segmax[i] = maxPair(segmax[i << 1], segmax[i << 1 | 1]);
}

inline int LCA (int x, int y) {
    while (chain[x] ^ chain[y]) {
        if (depth[head[chain[x]]] < depth[head[chain[y]]]) y = par[head[chain[y]]];
        else x = par[head[chain[x]]];
    }
    return depth[x] < depth[y] ? x : y;
}

inline void HLD_Update (int x, int y, int val) {
    if (par[x] == y) maxsegUpdate(ind[x], val);
    else if (par[y] == x) maxsegUpdate(ind[y], val);
    else assert(0);
}

// Query UP the chain to get the edge with the SECOND max weight!!!
inline pair<ll, ll> HLD_Query (int x, int y) {
    pair<ll, ll> maxedge = pair<ll, ll>(-INF, -INF);
    while (chain[x] ^ chain[y]) {
        maxedge = maxPair(maxedge, maxsegQuery(ind[head[chain[x]]], ind[x]));
        x = par[head[chain[x]]];
    }
    if (x == y) return maxedge;
    maxedge = maxPair(maxedge, maxsegQuery(ind[y] + 1, ind[x]));
    return maxedge;
}

inline pair<ll, ll> Query_Path (int x, int y) {
    int lca = LCA(x, y);
    if (depth[x] + depth[y] - (depth[lca] << 1) < 2) return mp(-1, -1);
    return maxPair(HLD_Query(x, lca), HLD_Query(y, lca));
}

int main () {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i=1; i<N; i++) {
        cin >> a >> b >> c;
        adj[--a].pb(mp(--b, c));
        adj[b].pb(mp(a, c));
    }
    cin >> Q;
    InitHLD();
    while (Q--) {
        cin >> a >> b;
        cout << Query_Path(--a, --b).f << "\n";
    }
    return 0;
}

/*
5
1 2 2
2 3 3
3 4 4
3 5 7
4
1 5
1 2
1 3
2 4

4
1 2 2
2 3 3
3 4 4
2
1 3
2 4
*/