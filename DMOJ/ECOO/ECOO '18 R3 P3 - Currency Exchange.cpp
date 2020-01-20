#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
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
#ifdef DEBUG
    #define D(x...) printf(x)
#else
    #define D(x...)
#endif
using namespace std;

int N, M, A, B;
long double dist[MAXN];
vector<pair<int, long double> > adj[MAXN];
bool is_cycle[MAXN];
long double C, D;

inline void Mark (int node) {
    if (is_cycle[node]) return;
    is_cycle[node] = 1;
    for (auto i : adj[node]) Mark(i.f);
}

void Do_Test_Cases () {
    int TEST_CASES = 10;
    while (TEST_CASES--) {
        for (int i=0; i<MAXN; i++) {
            adj[i].clear();
            dist[i] = 1e6;
            is_cycle[i] = 0;
        }
        cin >> N >> M >> D;
        dist[0] = -log10(D);
        while (M--) {
            cin >> A >> B >> C;
            adj[--A].pb(mp(--B, log10(C)));
        }
        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++) {
                for (size_t k=0; k<adj[j].size(); k++) {
                    pair<int, long double> &next = adj[j][k];
                    if (dist[next.f] > dist[j] + next.s) dist[next.f] = dist[j] + next.s;
                }
            }
        }
        for (int i=0; i<N; i++) {
            for (size_t k=0; k<adj[i].size(); k++) {
                pair<int, long double> &next = adj[i][k];
                if (dist[next.f] > dist[i] + next.s && dist[next.f] < 1e5) Mark(next.f);
            }
        }
        if (dist[N - 1] <= -9 || is_cycle[N - 1]) cout << "Billionaire!" << "\n";
        else cout << fixed << setprecision(2) << pow(10.0, -dist[N - 1]) << "\n";
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
    // freopen("DATA31.txt", "r", stdin);
    Do_Test_Cases();
    return 0;
}