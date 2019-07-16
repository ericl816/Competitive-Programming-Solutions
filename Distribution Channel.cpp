#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
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
using namespace std;

struct Node {
    int l, r, val;
};

struct Edge {
    int a, b, c;
    bool operator < (const Edge &a) const {
        return c < a.c;
    }
};

struct Disjoint {
private:
    int N;
    vi lead, rank;

public:
    Disjoint (int N) : N(N), lead(N + 1), rank(N + 1) { }

    void make_Set () {
        for (int i=0; i<N; i++) {
            lead[i] = i;
            rank[i] = 0;
        }
    }

    int Find (int x) {
        while (lead[x] ^ x) {
            lead[x] = lead[lead[x]];
            x = lead[x];
        }
        return x;
    }

    bool Merge (int x, int y) {
        return Find(x) ^ Find(y);
    }

    void Union (int x, int y) {
        int a = Find(x);
        int b = Find(y);
        if (Merge(x, y)) {
            if (rank[a] > rank[b]) {
                lead[b] = a;
                rank[a] += rank[b];
            }
            else {
                lead[a] = b;
                rank[b] += rank[a];
            }
        }
    }
} ds(MAXM);

int depth[MAXM], par[MAXM], subtree_size[MAXM], head[MAXM], chain[MAXM], vert[MAXM], weight[MAXM], ind[MAXM], arr[MAXM];
int idx, chainNum;
int N, M, a, b, c;
ll cheapest = INF, heaviestedge, totalcost;
vector<Edge> edgelist, unused;
vector<pii> MST[MAXN];

struct Seg {
private:
    int N;
    vector<Node> tree;

public:
    Seg (int N) : N(N), tree(N << 2) {
        for (int i=0; i<N; i++) arr[ind[i]] = weight[i];
        Build(1, 1, N);
    }

    void Push_Up (int idx) {
        tree[idx].val = max(tree[idx << 1].val, tree[idx << 1 | 1].val);
    }

    void Build (int idx, int l, int r) {
        tree[idx].l = l;
        tree[idx].r = r;
        if (l == r) {
            tree[idx].val = arr[l];
            return;
        }
        int mid = (l + r) >> 1;
        Build(idx << 1, l, mid);
        Build(idx << 1 | 1, mid + 1, r);
        Push_Up(idx);
    }

    void Update (int idx, int l, int r, int val) {
        if (tree[idx].l > r || tree[idx].r < l) return;
        if (tree[idx].l == l && tree[idx].r == r) {
            tree[idx].val = val;
            return;
        }
        int mid = (l + r) >> 1;
        if (r <= mid) Update(idx << 1, l, r, val);
        else if (l > mid) Update(idx << 1 | 1, l, r, val);
        else {
            Update(idx << 1, l, mid, val);
            Update(idx << 1 | 1, mid + 1, r, val);
        }
        Push_Up(idx);
    }

    inline void Update (int idx, int l, int r, int ind, int val) {
        if (l > ind || r < ind) return;
        if (l == r) {
            tree[idx].val = val;
            return;
        }
        int mid = (l + r) >> 1;
        Update(idx << 1, l, mid, ind, val);
        Update(idx << 1 | 1, mid + 1, r, ind, val);
        Push_Up(idx);
    }

    int Query (int idx, int l, int r) {
        if (tree[idx].l > r || tree[idx].r < l) return -1;
        if (tree[idx].l >= l && tree[idx].r <= r) {
            return tree[idx].val;
        }
        int mid = (l + r) >> 1;
        if (r <= mid) return Query(idx << 1, l, r);
        else if (l > mid) return Query(idx << 1 | 1, l, r);
        return max(Query(idx << 1, l, mid), Query(idx << 1 | 1, mid + 1, r));
    }

    int Query (int idx, int l, int r, int l1, int r1) {
        if (l1 > r || l > r1) return -1;
        if (l >= l1 && r <= r1) return tree[idx].val;
        int mid = (l + r) >> 1;
        return max(Query(idx << 1, l, mid, l1, r1), Query(idx << 1 | 1, mid + 1, r, l1, r1));
    }
} *seg;

inline void DFS (int node, int prev, int val) {
    depth[node] = val;
    par[node] = prev;
    subtree_size[node] = 1;
    for (size_t i=0; i<MST[node].size(); i++) {
        pii &next = MST[node][i];
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
    for (size_t i=0; i<MST[node].size(); i++) {
        pii &next = MST[node][i];
        if (next.f == prev) continue;
        if (maxidx == -1 || subtree_size[maxidx] < subtree_size[next.f]) maxidx = next.f;
    }
    if (~maxidx) HLD(maxidx, node);
    for (size_t i=0; i<MST[node].size(); i++) {
        pii &next = MST[node][i];
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
    seg = new Seg(N);
}

inline int LCA (int x, int y) {
    while (chain[x] ^ chain[y]) {
        if (depth[head[chain[x]]] < depth[head[chain[y]]]) y = par[head[chain[y]]];
        else x = par[head[chain[x]]];
    }
    return depth[x] < depth[y] ? x : y;
}

inline void HLD_Update (int x, int y, int val) {
    if (par[x] == y) seg->Update(1, 1, N, ind[x], val);
    else if (par[y] == x) seg->Update(1, 1, N, ind[y], val);
    else assert(0);
}

inline int HLD_Query (int x, int y) {
    int maxedge = 0;
    while (chain[x] ^ chain[y]) {
        maxedge = max(maxedge, seg->Query(1, 1, N, ind[head[chain[x]]], ind[x]));
        x = par[head[chain[x]]];
    }
    if (x == y) return maxedge;
    maxedge = max(maxedge, seg->Query(1, 1, N, ind[y] + 1, ind[x]));
    return maxedge;
}

inline int Query_Path (int x, int y) {
    int lca = LCA(x, y);
    return max(HLD_Query(x, lca), HLD_Query(y, lca));
}

int main () {
    #ifdef NOT_DMOJ
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif // NOT_DMOJ
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    ds.make_Set();
    if (M < N - 1) {
        cout << -1 << "\n";
        return 0;
    }
    for (int i=0; i<M; i++) {
        cin >> a >> b >> c;
        --a; --b;
        edgelist.pb((Edge) {a, b, c});
    }
    sort(edgelist.begin(), edgelist.end());
    for (size_t i=0; i<edgelist.size(); i++) {
        Edge &next = edgelist[i];
        if (ds.Merge(next.a, next.b)) {
            ds.Union(next.a, next.b);
            MST[next.a].pb(mp(next.b, next.c));
            MST[next.b].pb(mp(next.a, next.c));
            totalcost += next.c;
        }
        else unused.pb(next);
    }
    if (unused.empty()) {
        cout << -1 << "\n";
        return 0;
    }
    InitHLD();
    for (size_t i=0; i<unused.size(); i++) {
        Edge &next = unused[i];
        heaviestedge = Query_Path(next.a, next.b);
        if (heaviestedge == next.c) continue;
        cheapest = min(cheapest, totalcost + next.c - heaviestedge);
    }
    cout << (cheapest == INF ? -1 : cheapest) << "\n";
    return 0;
}