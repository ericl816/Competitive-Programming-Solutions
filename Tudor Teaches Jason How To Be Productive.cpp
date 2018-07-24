#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXM 1010
#define MAXN 510
#define INF 0x3f3f3f3f
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

int N, Q, a, b;
vi adj[MAXN];
bool vis[MAXN][MAXN];
int dist[MAXN][MAXN];
string words[MAXN];
queue<int> q;
bool flag;

inline bool isPoss (string c, string d) {
    if (abs((int) c.size() - (int) d.size()) > 1) return 0;
    else {
        // Change character
        if (c.size() == d.size()) {
            int res = 0;
            for (size_t i=0; i<c.size(); i++) if (c[i] != d[i]) res++;
            return res <= 1;
        }
        else {
            // Add character
            if (c.size() < d.size()) swap(c, d);
            for (size_t i=0, j=0; i<c.size() && j<d.size(); i++) {
                if (c[i] != d[j]) {
                    if (i == j) j--;
                    else return 0;
                }
                j++;
            }
            return 1;
        }
    }
}

inline void BFS () {
    memset(dist, INF, sizeof(dist));
    memset(vis, 0, sizeof(vis));
    for (int i=0; i<N; i++) {
        q.push(i);
        vis[i][i] = 1;
        dist[i][i] = 0;
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            for (size_t j=0; j<adj[curr].size(); j++) {
                int &next = adj[curr][j];
                if (!vis[i][next]) {
                    vis[i][next] = 1;
                    dist[i][next] = dist[i][curr] + 1;
                    q.push(next);
                }
            }
        }
    }
}

int main () {
    #ifdef NOT_DMOJ
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif // NOT_DMOJ
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i=0; i<N; i++) cin >> words[i];
    for (int i=0; i<N; i++) {
        for (int j=i + 1; j<N; j++) {
            if (isPoss(words[i], words[j])) {
                adj[i].pb(j);
                adj[j].pb(i);
            }
        }
    }
    BFS();
    cin >> Q;
    while (Q--) {
        cin >> a >> b;
        cout << (dist[--a][--b] == INF ? -1 : dist[a][b]) << "\n";
    }
    return 0;
}