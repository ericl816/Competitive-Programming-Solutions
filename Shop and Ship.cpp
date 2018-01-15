#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXN 5010
#define INF 0x3f3f3f3f
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define mii map<int, int>
#define umii unordered_map<int, int>
using namespace std;

int N, T, C, x, y, K, z, P, D;
int dist[MAXN];
int adj[MAXN][MAXN];
bool vis[MAXN];

int main () {
    scan(N); scan(T);
    memset(adj, INF, sizeof(adj));
    memset(dist, INF, sizeof(dist));
    for (int i=0; i<T; i++) {
        scan(x); scan(y); scan(C);
        adj[x][y] = C;
        adj[y][x] = C;
    }
    scan(K);
    for (int i=0; i<K; i++) {
        scan(z); scan(P);
        dist[z] = P;
    }
    for (int i=0; i<N; i++) {
        int node = 0;
        for (int j=1; j<=N; j++) {
            if (!vis[j] && dist[j] < dist[node]) node = j;
        }
        if (node == 0) break;
        vis[node] = 1;
        for (int j=1; j<=N; j++) {
            if (dist[node] + adj[node][j] < dist[j]) dist[j] = dist[node] + adj[node][j];
        }
    }
    scan(D);
    printf("%d\n", dist[D]);
    return 0;
}