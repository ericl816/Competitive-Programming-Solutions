#include <bits/stdc++.h>
#define ll long long
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define MAXM 510
#define MAXN 6050
#define MOD 100000000
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

// Problem Statement: http://poj.org/problem?id=3259
// Use Bellman Ford's to check to see if there's a negative cycle

struct Edge {
    int u, v, cost;
} ls[MAXN];

int F, V, E, e1, e2;
int j, k, cost;
int dist[MAXM];

int main() {
    scan(F);
    while (F--) {
        flag = 0;
        E = 0;
        scan(V); scan(e1); scan(e2);
        for (int i=0; i<e1; i++) {
            scan(j); scan(k); scan(cost);
            ls[E++] = (Edge) {--j, --k, cost};
            ls[E++] = (Edge) {k, j, cost};
        }
        for (int i=0; i<e2; i++ ) {
            scan(j); scan(k); scan(cost);
            ls[E++] = (Edge) {--j, --k, -cost};
        }
        memset(dist, 0, sizeof(dist));
        for (int i=0; i<V; i++)
            for (int j=0; j<E; j++)
                dist[ls[j].v] = min(dist[ls[j].v], dist[ls[j].u] + ls[j].cost);
        for (j=0; j<E; j++) {
            if (dist[ls[j].v] > dist[ls[j].u] + ls[j].cost) {
                flag = 1;
                break;
            }
        }
        if (!flag) printf("%s\n", "NO");
        else printf("%s\n", "YES");
    }
    return 0;
}