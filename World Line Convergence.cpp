#include <bits/stdc++.h>
#define ll long long 
#define MOD 1000000007
using namespace std;

const int MAXN = 200005;
ll BIT[MAXN];
map <int, int> m;
vector <int> adj[MAXN];

int N, POC, parent, root, ord;

void update(int i, long long a) {
    for (; i <= N; i += (i & -i))
        BIT[i]= (BIT[i] % MOD + a % MOD) % MOD;
}

ll query(int i) {
    ll ret = 0;
    for (; i > 0; i -= (i & -i))
        ret = (ret % MOD + BIT[i] % MOD) % MOD;
    return ret;
}

void DFS(int cur, int next) {
    ll idx = query(m[cur]);
    for (int temp : adj[cur]) {
        if (temp ^ next) DFS(temp, cur);
    }
    update(m[cur], query(m[cur]) + 1 - idx);
}

int main() {
    scanf("%d", &N);
    for (int i=1; i<=N; i++) {
        scanf("%d", &parent);
        if (parent == 0) root = i;
        else {
            adj[parent].push_back(i);
            adj[i].push_back(parent);
        }
    }
    for (int i=1; i<=N; i++) {
        scanf("%d", &ord);
        m[ord] = i;
    }
    DFS(root, -1);
    for (int i=1; i<=N; i++) 
        printf("%lld ", (query(m[i]) % MOD - (query(m[i] - 1)) % MOD + MOD) % MOD);
}
