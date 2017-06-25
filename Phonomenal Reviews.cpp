#include<bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define pb push_back
using namespace std;
const int MAXN = 100010;
int N, M, pho, a, b, r, paths = 0;
vector<int> v[MAXN];
bool u[MAXN];
bool p[MAXN];
bool k[MAXN];
int d[MAXN];

bool DFS(int N) {
    if (u[N]) return 0;
    u[N] = 1;
    k[N] = p[N];
    for (int i=0; i<v[N].size(); i++) {
        if (!u[v[N][i]]) {
            DFS(v[N][i]);
            k[N] = k[N] || k[v[N][i]];
            if (k[v[N][i]]) paths++;
        }
    }
    return k[N];
}

void DFS2(int N, int D) {
    if (u[N] || !k[N]) return;
    u[N] = 1;
    d[N] = D;
    if (d[N] > d[r]) r = N;
    for (int i=0; i<v[N].size(); i++) DFS2(v[N][i], D+1);
    
}

int main() {
    scan(N);
    scan(M);
    for (int i=0; i<M; i++) {
        scan(pho);
        p[pho] = 1;
    }
    for (int i=0; i<N - 1; i++) {
        scan(a);
        scan(b);
        v[a].pb(b);
        v[b].pb(a);
    }
    DFS(pho);
    memset(u, 0, sizeof u);
    DFS2(pho, 0);
    memset(u, 0, sizeof u);
    DFS2(r, 0);
    printf("%d\n", (paths << 1) - d[r]);
}
