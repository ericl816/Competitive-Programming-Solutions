#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXM 1010
#define MAXN 5010
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

struct Query {
    ll src, dest, limit;
    bool flag;
    
    bool operator < (const Query &a) {
      if (limit ^ a.limit) return limit < a.limit;
      return src < a.src;
    }
};

ll N, M, K, S, T, ans;
ll A[MAXN], B[MAXN], C[MAXN], D[MAXN];
bool vis[MAXN];
vector<Query> query;
set<int> adj[MAXM];

inline bool BFS (int src, int dest) {
    queue<int> q;
    memset(vis, 0, sizeof(vis));
    q.push(src);
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        if (curr == dest) return 1;
        for (auto next : adj[curr]) {
            if (!vis[next]) {
                vis[next] = 1;
                q.push(next);
            }
        }
    }
    return 0;
}

int main () {
    scan(N); scan(M); scan(K); scan(S); scan(T);
    for (int i=0; i<M; i++) {
        scan(A[i]); scan(B[i]); scan(C[i]); scan(D[i]);
    }
    for (int i=0; i<M; i++) {
        query.pb((Query) {A[i], B[i], C[i], 1});
        query.pb((Query) {A[i], B[i], D[i] + 1, 0});
    }
    sort(query.begin(), query.end());
    for (size_t i=0; i<query.size() - 1; i++) {
        if (query[i].flag) adj[query[i].src].insert(query[i].dest);
        else adj[query[i].src].erase(query[i].dest);
        if (BFS(S, T)) ans += query[i + 1].limit - query[i].limit;
    }
    return !printf("%lld\n", ans);
}