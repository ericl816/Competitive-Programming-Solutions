#include <bits/stdc++.h>
#define ll long long
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define MAXN 200010
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define mii map<int, int>
#define umii unordered_map<int, int>
using namespace std;

int N, POC, parent, root, ord;
ll BIT[MAXN];
umii m;
vi adj[MAXN];

void Update (int idx, ll val) {
    for (; idx<=MAXN; idx+=idx & -idx) BIT[idx] = (BIT[idx] % MOD + val % MOD) % MOD;
}

ll Query (int idx) {
    ll sum = 0;
    for (; idx; idx-=idx & -idx) sum = (sum % MOD + BIT[idx] % MOD) % MOD;
    return sum;
}

inline void DFS (int node, int prev) {
    ll idx = Query(m[node]);
    for (int &next : adj[node]) {
        if (next == prev) continue;
        DFS(next, node);
    }
    Update(m[node], Query(m[node]) - idx + 1);
}

int main () {
    scan(N);
    for (int i=1; i<=N; i++) {
        scan(parent);
        if (!parent) root = i;
        else {
            adj[parent].pb(i);
            adj[i].pb(parent);
        }
    }
    for (int i=1; i<=N; i++) {
        scan(ord);
        m[ord] = i;
    }
    DFS(root, -1);
    for (int i=1; i<=N; i++) printf("%lld ", (Query(m[i]) % MOD - (Query(m[i] - 1)) % MOD + MOD) % MOD);
    return 0;
}