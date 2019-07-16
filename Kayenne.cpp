#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define ull unsigned long long
#define MAXM 410
#define MAXN 110
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
int Cx, Cy;
double per;
bool exist[MAXM][MAXM];
char op;

struct P {
    int d, t;
    bool operator < (const P &e) const {
        return d > e.d;
    }
};

inline int Dist (int a, int b, int c, int d) {
    return abs(a - c) * abs(a - c) + abs(b - d) * abs(b - d);
}

inline void Do_Test_Cases () {
    while (TEST_CASES--) {
        cin >> Cx >> Cy;
        per = 0;
        int tot = 0, d = 0, r = 0;
        memset(exist, 0, sizeof(exist));
        set<pair<int, pii> > H;
        for (int i=0, x, y; i<100; i++) {
            cin >> x >> y >> op;
            exist[x + 200][y + 200] = 1;
            H.insert(mp(op == 'D', mp(x, y)));
        }
        for (int i=Cx - 50; i<=Cx + 50; i++) {
            for (int j=Cy - 50; j<=Cy + 50; j++) {
                if (Dist(Cx, Cy, i, j) <= 50 * 50 && !exist[i + 200][j + 200]) {
                    ++tot;
                    priority_queue<P> pq;
                    for (auto k : H) {
                        pq.push((P) {Dist(i, j, k.s.f, k.s.s), k.f});
                    }
                    int dcnt = 0, rcnt = 0, tie = 0;
                    for (int k=0; k<3; k++) {
                        P curr = pq.top();
                        pq.pop();
                        tie = curr.d;
                        if (!curr.t) ++rcnt;
                        else ++dcnt;
                    }
                    // D("%d\n", tie);
                    while (!pq.empty() && pq.top().d == tie) {
                        P curr = pq.top();
                        pq.pop();
                        tie = curr.d;
                        if (!curr.t) ++rcnt;
                        else ++dcnt;
                    }
                    if (dcnt >= rcnt) ++d;
                }
            }
        }
        // D("%d %d\n", d, tot);
        per = 100.0 * d / tot;
        cout << fixed << setprecision(1) << per << "\n";
    }
}

int main () {
    #ifdef NOT_DMOJ
    freopen("DATA11.txt", "r", stdin);
    freopen("DATA11out.txt", "w", stdout);
    #endif // NOT_DMOJ
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Do_Test_Cases();
    return 0;
}