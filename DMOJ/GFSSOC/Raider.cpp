#include <bits/stdc++.h>
#define ll long long
#define MAXN 500010
#define INF 0x3f3f3f3f
#define MOD 1000000007
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

int N, M, idx, cnt, a, b;
int coins[MAXN], low[MAXN], DFN[MAXN], comp[MAXN], total[MAXN];
pii DP[MAXN][2];
vi adj[MAXN];
stack<int> SCC;
set<int> DAG[MAXN];
bool processed[MAXN];

inline void TarjansDFS (int node, int prev) {
    low[node] = DFN[node] = idx++;
    SCC.push(node);
    processed[node] = 1;
    for (size_t i=0; i<adj[node].size(); i++) {
        int &next = adj[node][i];
        if (next == prev) continue;
        if (!DFN[next]) {
            TarjansDFS(next, node);
            low[node] = min(low[node], low[next]);
        }
        else if (processed[next]) low[node] = min(low[node], DFN[next]);
    }
    if (low[node] == DFN[node]) {
        while (SCC.top() ^ node) {
            int curr = SCC.top();
            comp[curr] = cnt;
            total[cnt] += coins[curr];
            processed[curr] = 0;
            SCC.pop();
        }
        int curr = SCC.top();
        comp[curr] = cnt;
        total[cnt] += coins[curr];
        processed[curr] = 0;
        SCC.pop();
        cnt++;
    }
}

void Reconstruct_DAG () {
    for (int i=1; i<=N; i++) {
        for (size_t j=0; j<adj[i].size(); j++) {
          int &next = adj[i][j];
          if (comp[i] ^ comp[next]) DAG[comp[i]].insert(comp[next]);
        }
        adj[i].clear();
    }
}

pii Solve (int node, bool choose) {
    if (node == comp[N]) {
        if (choose) return pii(total[node], 1);
        return pii(0, 1);
    }
    if (DP[node][choose] != pii(-1, -1)) return DP[node][choose];
    pii ans = pii(-INF, 0), res;
    for (auto next : DAG[node]) {
        if (choose) {
            res = Solve(next, 0);
            res.f += total[node];
            if (res.f > ans.f) ans = res;
            else if (res.f == ans.f) {
                ans.s += res.s;
                ans.s %= MOD;
            }
        }
        res = Solve(next, 1);
        if (res.f > ans.f) ans = res;
        else if (res.f == ans.f) {
            ans.s += res.s;
            ans.s %= MOD;
        }
    }
    return DP[node][choose] = ans;
}

int main () {
    scanf("%d %d", &N, &M);
    for (int i=1; i<=N; i++) DP[i][0] = DP[i][1] = pii(-1, -1);
    for (int i=1; i<=N; i++) scanf("%d", &coins[i]);
    for (int i=0; i<M; i++) {
        scanf("%d %d", &a, &b);
        adj[a].pb(b);
    }
    TarjansDFS(1, -1);
    Reconstruct_DAG();
    pii ans = Solve(comp[1], 1);
    return !printf("%d %d\n", ans.f, ans.s);
}