#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define ull unsigned long long
#define MAXN 1000010
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

/*
You are playing a game with Bruce involving 𝑁 coins laid out in a row.

The two players alternate taking coins from either end of the row. The game ends when no more coins remain.

Bruce is a genius and will always play optimally. However, he is nice and will let you make the first move.

What is the maximum total value of coins you can take?

Overall Time Complexity: O(NlogN)
*/

int N, s1, s2;
int A[MAXN];
vi V;

int main (int argc, char const *argv[]) {
    #ifdef NOT_DMOJ
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif // NOT_DMOJ
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> A[i];
        s1 += A[i];
    }
    for (int i=0; i<N; i++) {
        V.pb(A[i]);
        while (V.size() > 2 && V[V.size() - 3] <= V[V.size() - 2] && V[V.size() - 2] >= V[V.size() - 1]) {
            int res = V[V.size() - 3] - V[V.size() - 2] + V[V.size() - 1];
            V.pop_back(), V.pop_back(), V.pop_back();
            V.pb(res);
        }
    }
    sort(allof(V), greater<int>());
    for (size_t i=0; i<V.size(); i++) {
        if (i & 1) s2 -= V[i];
        else s2 += V[i];
    }
    cout << ((s1 + s2) >> 1) << "\n";
    return 0;
}

/* 
 * Look for:
 * the exact constraints (multiple sets are too slow for n=10^6 :( ) 
 * special cases (n=1?)
 * overflow (ll vs int?)
 * array bounds
 */