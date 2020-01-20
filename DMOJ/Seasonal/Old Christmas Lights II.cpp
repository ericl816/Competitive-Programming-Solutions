#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXN 50010
#define MAXLOG 17
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

vi adj[MAXN], vec;
unordered_map<int, vi> cust[MAXN];
int N, Q, a, b;
int h[MAXN], bright[MAXN];
bool vis[MAXN], flag;

void dfs (int node, int prev, int val) {
    h[node] = val;
    for (size_t i=0; i<adj[node].size(); i++) {
        if (adj[node][i] == prev) continue;
        dfs(adj[node][i], node, val + 1);
    }
}

int main() {
    scan(N);
    scan(Q);
    for (int i=1; i<=N; i++) scan(bright[i]);
    int a, b;
    for (int i = 1;i < N;i++) {
        scan(a);
        scan(b);
        adj[a].pb(b);
        adj[b].pb(a);
    }

    dfs(1, -1, 0);

    for (int i = 0; i < Q;i++) {
        scan(a);
        scan(b);
        vector<int> v;
        bool custed = false;
        int abal = -1, bbal = -1;
        while (h[a] != h[b]) {
            if (h[a] > h[b]) {
                for (int j : adj[a])
                    if (h[j] < h[a]) {
                        v.push_back(bright[a]);
                        a = j;
                        break;
                    }
            }
            else if (h[b] > h[a]) {
                for (int j : adj[b])
                    if (h[j] < h[b]) {
                        v.push_back(bright[b]);
                        b = j;
                        break;
                    }
            }
        }
        vector<int> cus;
        abal = a;bbal = b;
        while (a ^ b) {
            if (cust[a].find(b) != cust[a].end()) {
                vector<int> custsu = cust[a][b];
                v.insert(end(v), begin(custsu), end(custsu));
                custed = true;
                break;
            }
            for (int j : adj[a])
                if (h[j] < h[a]) {
                    cus.push_back(bright[a]);
                    a = j;
                    break;
                }
            for (int j : adj[b])
                if (h[j] < h[b]) {
                    cus.push_back(bright[b]);
                    b = j;
                    break;
                }
        }
        if (!custed) {
            cus.push_back(bright[a]);
            cust[abal][bbal] = cus;
            cust[bbal][abal] = cus;
            v.insert(end(v), begin(cus), end(cus));
        }
        sort(v.begin(), v.end());
        int small = -1;
        for (int i = 1;i < v.size();i++) {
            if (small == -1 || v[i] - v[i - 1] < small)
                small = v[i] - v[i - 1];
        }
        printf("%d\n", small);
    }
    return 0;
}