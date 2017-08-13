#include <bits/stdc++.h>
#define ll long long 
#define MAXN 100010
#define vi vector<int>
#define pq priority_queue<int>
#define pb push_back
#define p push
using namespace std;

int n, m, v, u, indegree[MAXN], outdegree[MAXN], ans[MAXN], cnt;
vi vec[MAXN];
pq q;

int main() {
    scanf("%d %d", &n, &m);
    cnt = n;
    for (int i=0; i<m; i++) {
        scanf("%d %d", &v, &u);
        vec[u].pb(v);
        outdegree[v]++;
    }
    for (int i=1; i<=n; i++) {
        if (!outdegree[i]) q.p(i);
    }
    while (!q.empty()) {
        int curr = q.top(); 
        q.pop();
        ans[curr] = cnt;
        cnt--;
        for (int i=0; i<vec[curr].size(); i++) {
            outdegree[vec[curr][i]]--;
            if (!outdegree[vec[curr][i]]) q.p(vec[curr][i]);
        }
    }
    for (int i=1; i<=n; i++) printf("%d ", ans[i]);
}
