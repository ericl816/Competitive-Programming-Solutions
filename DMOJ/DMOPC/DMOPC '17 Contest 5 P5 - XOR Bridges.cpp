#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC optimize "omit-frame-pointer"
#pragma GCC optimize "prefetch-loop-arrays"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,aes,sse4a,sse4.1,sse4.2,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define ull unsigned long long
#define MAXN 200010
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) < (b) ? (b) : (a))
#define vi vector<int>
#define vll vector<ll>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define mii map<int, int>
#define umii unordered_map<int, int>w
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

int N, M, Q;
vector<pii> acc;

struct Disjoint {
private:
    int N;
    vi lead, rank;

public:
    Disjoint (int N) : N(N), lead(N + 1), rank(N + 1) { }

    void make_Set () {
        for (int i=0; i<N; i++) {
            lead[i] = i;
            rank[i] = 0;
        }
    }

    int Find (int x) {
        while (lead[x] ^ x) {
            lead[x] = lead[lead[x]];
            x = lead[x];
        }
        return x;
    }

    bool Merge (int x, int y) {
        return Find(x) ^ Find(y);
    }

    void Rank (int x, int y) {
        int a = Find(x);
        int b = Find(y);
        if (Merge(x, y)) {
            if (rank[a] > rank[b]) {
                lead[b] = a;
                rank[a] += rank[b];
            }
            else {
                lead[a] = b;
                rank[b] += rank[a];
            }
        }
    }

    void Rank (int bit, vector<pii> &vec) {
        if (bit == -1 || vec.size() < 2) {
            for (int i=1; i<vec.size(); i++) Rank(vec[0].f, vec[i].f);
            return;
        }
        if (M & (1 << bit)) {
            for (int i=1; i<vec.size(); i++) Rank(vec[0].f, vec[i].f);
            Rank(bit - 1, vec);
        }
        else {
            vector<pii> vec1, vec2;
            for (int i=0; i<vec.size(); i++) {
                if (vec[i].s & (1 << bit)) vec1.pb(vec[i]);
                else vec2.pb(vec[i]);
            }
            Rank(bit - 1, vec1);
            Rank(bit - 1, vec2);
        }
    }
};

Disjoint ds(MAXN);

int main (int argc, char const *argv[]) {
    #ifdef NOT_DMOJ
    freopen("DATA.in", "r", stdin);
    freopen("DATA.out", "w", stdout);
    #endif // NOT_DMOJ
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M >> Q;
    ds.make_Set();
    for (int i=0, x; i<N; i++) {
        cin >> x;
        acc.pb(mp(i, x));
    }
    ds.Rank(30, acc);
    for (int i=0, p, q; i<Q; i++) {
        cin >> p >> q;
        cout << (ds.Merge(--p, --q) ? "NO" : "YES") << "\n";
    }
    return 0;
}

/* 
 Look for:
 * the exact constraints (multiple sets are too slow for n=10^6 :( ) 
 * special cases (n=1?)
 * overflow (ll vs int?)
 * array bounds
 * number of test cases (T = 10)
 * resetting containers, variables, etc
 */