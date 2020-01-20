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

int B, G;
ll fact[MAXN];

inline ll Choose (int N, int K) {
    return (fact[N] % MOD / (fact[K] % MOD * fact[N - K] % MOD)) % MOD;
}

inline void Do_Test_Cases () {
    int TEST_CASES = 10;
    while (TEST_CASES--) {
        cin >> B >> G;
        if (G < 2) cout << 0 << "\n";
        else {
            ll res = 0LL;
            for (int gap=0; gap * (G - 1)<=B; gap+=2) res = (res + B - gap * (G - 1) + 1) % MOD;
            // D("%lld\n", res);
            ll ans = (fact[B + G] % MOD - (res * fact[B] % MOD * fact[G] % MOD) % MOD) % MOD;
            cout << ((ans + MOD) % MOD) << "\n";
        }
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
    fact[1] = 1LL;
    for (int i=2; i<=MAXN; i++) fact[i] = (fact[i - 1] % MOD * i % MOD) % MOD;
    Do_Test_Cases();
    return 0;
}