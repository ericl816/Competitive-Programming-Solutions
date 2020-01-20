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

int TEST_CASES = 10;
int R, T;
char C;
string S, A;

inline void Do_Test_Cases () {
    while (TEST_CASES--) {
        cin >> R >> T >> A;
        ll len = 0;
        map<char, string> m;
        map<char, ll> mm1, mm2;
        for (auto i : A) mm1[i]++;
        char first = A[0], lastt = A.back();
        for (int i=0; i<R; i++) {
            cin >> C >> S;
            m[C] = S;
        }
        for (int i=0; i<T; i++) {
            first = m[first][0];
            lastt = m[lastt][m[lastt].size() - 1];
            for (auto j : mm1) {
                for (auto k : m[j.f]) {
                    mm2[k] += j.s;
                }
            }
            mm1 = mm2;
            mm2.clear();
        }
        for (auto i : mm1) len += i.s;
        cout << first << lastt << " " << len << "\n";
        fflush(stdout);
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

/* 
 Look for:
 * the exact constraints (multiple sets are too slow for n=10^6 :( ) 
 * special cases (n=1?)
 * overflow (ll vs int?)
 * array bounds
 * number of test cases (T = 10)
 * resetting containers, variables, etc
 */