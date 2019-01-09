#include <bits/stdc++.h>
#define ll long long
#define MAXN 100010
#define INF 0x3f3f3f3f
#define pb push_back
#define pii pair<int, int>
#define f first
#define s second
#define mp make_pair
using namespace std;

int N, M, Q, u, v, l, node1, node2;
int src[MAXN], len[MAXN]; 
ll length, cnt, maxh, minh; 
bool flag, vis[MAXN];
vector<pii> vec[MAXN]; 

void DFS1(int node, int par, ll dist) {
    vis[node] = 1;
    //vis[node] |= flag;
    if(length < dist) { 
        node1 = node;
        length = dist;
    }
    for(pii next : vec[node]) {
        int curr = next.f;
        int cost = next.s;
        if(!vis[curr]) DFS1(curr, node, cost + dist);
    }
}

void DFS2(int node, int par, ll dist) {
    if(length < dist) { 
        node2 = node;
        length = dist;
     }
    for(pii next : vec[node]){
        int curr = next.f;
        int cost = next.s;
        if(curr == par) continue;
        src[curr] = node; 
        len[curr] = cost;
        DFS2(curr, node, cost + dist);
    }
}

int main() {
    scanf("%d %d %d", &N, &M, &Q);
    for(int i=1; i<=M; i++) {
        scanf("%d %d %d", &u, &v, &l);
        vec[u].pb(mp(v, l));
        vec[v].pb(mp(u, l));
    }

    for(int i=0; i<N; i++) {
        if(!vis[i + 1]) {
            length = -1;
            DFS1(i + 1, -1, 0);
            length = -1; 
            DFS2(node1, -1, 0);
            if(Q == 1) {
                length++;
                maxh += length;
                flag = 1;
            }
            else if (Q == 2) {
                ll cnt = INF;
                ll dist = 0;
                int curr = node2;
                while (curr ^ 0) {
                    dist += len[curr]; 
                    cnt = min(cnt, max(dist, length - dist));
                    curr = src[curr];
                }
                if(maxh <= cnt) { 
                    minh = maxh;
                    maxh = cnt; 
                }
            }
        }
    }
    printf("%lld\n", (flag ? maxh - 1 : max(maxh, minh + 1)));
    return 0;
}
