#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define ull unsigned long long
#define MAXN 200010
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define SEED 131
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

int N, M;
ll hashed[MAXN], qpow[MAXN];
ll ans;
string s;
vi vals;

inline ll Get_Hash_Substr (ll a, ll b) {
    ll len = b - a + 1;
    return ((hashed[b] - (hashed[a - 1] * qpow[len]) % MOD) + MOD) % MOD;
}

int main (int argc, char const *argv[]) {
    #ifdef NOT_DMOJ
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif // NOT_DMOJ
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> s;
    qpow[0] = hashed[0] = 1LL;
    for (size_t i=1; i<=s.size(); i++) {
        hashed[i] = ((((hashed[i - 1] * SEED) + s[i - 1] - 'a' + 1) % MOD) + MOD) % MOD;
        qpow[i] = (((qpow[i - 1] * SEED) % MOD) + MOD) % MOD;
    }
    for (int i=1; i<=N; i++) {
        ll s1 = Get_Hash_Substr(0, i), s2 = Get_Hash_Substr(N - i, N);
        if (s1 == s2) vals.pb(i);
    }
    for (int i=0; i<N; i++) {
        if (i + vals[0] <= N && Get_Hash_Substr(0, vals[0]) == Get_Hash_Substr(i, i + vals[0])) {
            int lo = 0, hi = vals.size();
            while (lo <= hi) {
                int mid = (lo + hi) >> 1;
                if (i + vals[mid] <= N && Get_Hash_Substr(0, vals[mid]) == Get_Hash_Substr(i, i + vals[mid])) lo = mid + 1;
                else hi = mid - 1;
            }
            ans += lo;
        }
    }
    cout << ans << "\n";
    return 0;
}

/*
6
aabaaa
Ans: 9
*/

/* 
 * Look for:
 * the exact constraints (multiple sets are too slow for n=10^6 :( ) 
 * special cases (n=1?)
 * overflow (ll vs int?)
 * array bounds
 */