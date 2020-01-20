#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXN 2010
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
#ifdef DEBUG
  #define D(x...) printf(x)
#else
  #define D(x...)
#endif
using namespace std;

struct Edge {
  int nodex, nodey, cost;
};

int N, X, Y;
int memo[MAXN], dist[MAXN], dist1[MAXN];
vector<pii> loc;
vector<Edge> edges;

inline int EuclideanDist(const pii &a, const pii &b){
    return (a.f - b.f) * (a.f - b.f) + (a.s - b.s) * (a.s - b.s);
}

inline bool Cmp (Edge &a, Edge &b){
    return a.cost < b.cost;
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
    for (int i=0; i<N; i++) {
      cin >> X >> Y;
      loc.pb(mp(X, Y));
    }
    pii orig = mp(0, 0);
    for (int i=0; i<N; i++) edges.pb((Edge) {N, i, EuclideanDist(loc[i], orig)});
    for (int i=0; i<N; i++) for (int j=i + 1; j<N; j++) edges.pb((Edge) {i, j, EuclideanDist(loc[i], loc[j])});
    sort(edges.begin(), edges.end(), Cmp);
    for (int i=0; i<edges.size(); i++) {
        Edge &next = edges[i];
        if (next.cost > dist[next.nodex]) {
          dist[next.nodex] = next.cost;
          dist1[next.nodex] = memo[next.nodex];
        }
        if (next.cost > dist[next.nodey]) {
          dist[next.nodey] = next.cost;
          dist1[next.nodey] = memo[next.nodey];
        }
        if (next.nodex == N) memo[N] = max(memo[N], dist1[next.nodey] + 1);
        else if (next.nodey == N) memo[N] = max(memo[N], dist1[next.nodex] + 1);
        else {
            memo[next.nodex] = max(memo[next.nodex], dist1[next.nodey] + 1);
            memo[next.nodey] = max(memo[next.nodey], dist1[next.nodex] + 1);
        }
    }
    cout << memo[N] << "\n";
    return 0;
}

/* 
 * Look for:
 * the exact constraints (multiple sets are too slow for n=10^6 :( ) 
 * special cases (n=1?)
 * overflow (ll vs int?)
 * array bounds
 */