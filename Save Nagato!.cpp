#include <bits/stdc++.h>
using namespace std;

const int MAXN = 500001;
int N, u, v;
vector<int> adj[MAXN];
int max1[MAXN], max2[MAXN], idx[MAXN], dp[MAXN];

void dfs(int cur, int next) {
    for (int i=0; i<adj[cur].size(); i++) {
        int curr = adj[cur][i];
        if (!(curr ^ next)) continue;
        dfs(curr, cur);
        if (max1[cur] < max1[curr] + 1) {
            max2[cur] = max1[cur];
            max1[cur] = max1[curr] + 1;
            idx[cur] = curr;
        }
        else if (max2[cur] < max1[curr] + 1) {
            max2[cur] = max1[curr] + 1;
        }
    }
}

void recur(int min, int cur, int next) {
    dp[cur] = max(min, max1[cur]);
    for (int i = 0; i < adj[cur].size(); i++) {
        int curr = adj[cur][i];
        if (!(curr ^ next)) continue; 
        if (curr == idx[cur]) recur(max(min + 1 , max2[cur] + 1), curr, cur);
        else recur(max(min + 1 , max1[cur] + 1), curr, cur);
    }
}

int main() {
    scanf("%d", &N);
    for (int i=0; i<N-1; i++) {
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, -1);
    recur(0, 1, -1);
    for (int i=1; i<=N; i++)
        printf("%d\n", dp[i] + 1);
}
