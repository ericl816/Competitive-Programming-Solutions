#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define ull unsigned long long
#define MAXN 5010
#define MOD 1000000007
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
#define allof(x) x.begin(), x.end()
#define DEBUG 1
// #define NOT_DMOJ 0
#ifdef DEBUG
    #define D(x...) printf(x)
#else
    #define D(x...)
#endif
using namespace std;

inline int GCD (int a, int b) { return b == 0 ? a : GCD(b, a % b); }
inline int LCM (int a, int b) { return a * b / GCD(a, b); }
inline ll PowMod (ll a, ll b, ll mod) { ll val = 1; while (b) { if (b & 1) val = (val * a) % mod; a = (a * a) % mod; b >>= 1; } return val; }

int TEST_CASES = 10;
int N;
pair<ll, ll> p[MAXN];
set<pair<ll, ll> > se;

inline ll Dist (int ind1, int ind2) {
    return (p[ind1].s - p[ind2].s) * (p[ind1].s - p[ind2].s) + (p[ind1].f - p[ind2].f) * (p[ind1].f - p[ind2].f);
}

inline void Do_Test_Cases () {
    while (TEST_CASES--) {
        // Put code here.
        cin >> N;
        int ans = 0;
        for (int i=1; i<=N; i++) cin >> p[i].f >> p[i].s;
        if (N & 1) cout << 0 << "\n";
        else {
            for (int i=1; i<=N / 2; i++) {
                se.clear();
                int j = i + N / 2;
                bool flag = 1;
                for (int k=i + 1; k<j; k++) se.insert(mp(Dist(k, i), Dist(k, j)));
                for (int k=i + 1; k<j; k++) {
                    int ind = (k + N / 2 + N - 1) % N + 1;
                    // D("%d %d %d\n", ind, i, j);
                    if (se.find(mp(Dist(ind, i), Dist(ind, j))) == se.end()) {
                        flag = 0;
                        break;
                    }
                }
                ans += flag;
            }
            cout << ans << "\n";
        }
    }
}

int main () {
    #ifdef NOT_DMOJ
    freopen("Desktop/ECOO_2019/Round_2/DATA22.txt", "r", stdin);
    freopen("Desktop/ECOO_2019/Round_2/DATA22out.txt", "w", stdout);
    #endif // NOT_DMOJ
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Do_Test_Cases();
    return 0;
}
/*
4
0 0
1 1
1 2
2 0

4
0 0
0 1
1 1
1 0
*/

/* 
 Look for:
 * the exact constraints (multiple sets are too slow for n=10^6 :( ) 
 * special cases (n=1?)
 * overflow (ll vs int?)
 * array bounds
 * number of test cases (T = 10)
 * resetting containers, variables, etc
 */