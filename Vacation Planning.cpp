#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define ull unsigned long long
#define MAXM 210
#define MAXN 20010
#define INF 0x3f3f3f3f
#define min(a, b) (a) < (b) ? (a) : (b)
#define max(a, b) (a) < (b) ? (b) : (a)
#define vi vector<int>
#define vll vector<ll>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define mii map<int, int>
#define umii unordered_map<int, int>
#define DEBUG 1
#ifdef DEBUG
	#define D(x...) printf(x)
#else
	#define D(x...)
#endif
using namespace std;

// http://www.usaco.org/index.php?page=viewproblem2&cpid=364

int N, M, K, Q, u, v, d, a, b;
int city[MAXN], idx[MAXN];
int dist[MAXM][MAXN];
int val[MAXM][MAXM];
vector<pii> adj[MAXN], rev_adj[MAXN];
ll ans1, ans2;

int main (int argc, char const *argv[]) {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    cin >> N >> M >> K >> Q;
    for (int i=0; i<M; i++) {
        cin >> u >> v >> d;
        adj[u].pb(mp(v, d));
        rev_adj[v].pb(mp(u, d));
    }
    for (int i=1; i<=K; i++) {
        cin >> city[i];
        idx[city[i]] = i;
    }
    for (int i=1; i<=K; i++) {
        for (int j=1; j<=K; j++) {
            val[i][j] = i == j ? 0 : INF;
        }
    }
    for (int i=1; i<=K; i++) {
        for (size_t j=0; j<adj[city[i]].size(); j++) {
            pii &next = adj[city[i]][j];
            if (idx[next.f]) {
                val[i][idx[next.f]] = min(val[i][idx[next.f]], next.s);
                continue;
            }
            for (size_t j=0; j<adj[next.f].size(); j++) {
                if (idx[adj[next.f][j].f]) {
                    val[i][idx[adj[next.f][j].f]] = min(val[i][idx[adj[next.f][j].f]], next.s + adj[next.f][j].s);
                }
            }
        }
    }
    // Floyd warshall: O(K^3)
    for (int i=1; i<=K; i++) {
        for (int j=1; j<=K; j++) {
            for (int k=1; k<=K; k++) {
                val[j][k] = min(val[j][k], val[i][k] + val[j][i]);
            }
        }
    }
    for (int i=1; i<=K; i++) {
        for (int j=1; j<=N; j++) {
            if (idx[j]) {
                dist[i][j] = val[i][idx[j]];
                continue;
            }
            dist[i][j] = INF;
            for (size_t k=0; k<rev_adj[j].size(); k++) {
                dist[i][j] = min(dist[i][j], val[i][idx[rev_adj[j][k].f]] + rev_adj[j][k].s);
            }
        }
    }
    for (int i=0; i<Q; i++) {
        cin >> a >> b;
        if (idx[a]) {
            if (dist[idx[a]][b] < INF) {
                ans1++;
                ans2 += (ll) dist[idx[a]][b];
            }
            continue;
        }
        int res = INF;
        for (size_t j=0; j<adj[a].size(); j++) {
            pii &next = adj[a][j];
            res = min(res, dist[idx[next.f]][b] + next.s);
        }
        if (res < INF) {
            ans1++;
            ans2 += (ll) res;
        }
    }
    cout << ans1 << "\n" << ans2 << "\n";
	return 0;
}

/* 
 * Look for:
 * the exact constraints (multiple sets are too slow for n=10^6 :( ) 
 * special cases (n=1?)
 * overflow (ll vs int?)
 * array bounds
 */