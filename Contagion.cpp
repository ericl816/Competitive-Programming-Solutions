#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXN 30010
#define INF 0x3f3f3f3f3f3f3f3f
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

int N, X;
ll dist[MAXN], Q, q;
pii adj[MAXN];
bool vis[MAXN];

inline ll Dist (const ll &x, const ll &y) {
    return x * x + y * y;
}

int main () {
    scan(N);
    for (int i=0; i<N; i++) {
        scan(adj[i].f);
        scan(adj[i].s);
    }
    scan(X);
    memset(dist, 0x3f, sizeof dist);
    dist[X - 1] = 0;
    for (int i=1; i<N; i++) {
        ll minn = INF;
        int node = -1;
        for (int j=0; j<N; j++) {
            if (!vis[j] && dist[j] < minn) {
                minn = dist[j];
                node = j;
            }
        }
        vis[node] = 1;
        for (int j=0; j<N; j++) if (!vis[j]) dist[j] = min(dist[j], dist[node] + Dist(adj[node].f - adj[j].f, adj[node].s - adj[j].s));
    }
    sort(dist, dist + N);
    scan(Q);
    for (int i=0; i<Q; i++) {
        scan(q);
        printf("%d\n", upper_bound(dist, dist + N, q) - dist);
    }
}