#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define ull unsigned long long
#define MAXN 10000010
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

int TEST_CASES = 5;
int x;
bool isPrime[MAXN];
vi primes;
set<ll> s;

inline void Sieve () {
    memset(isPrime, 1, sizeof(isPrime));
    for (int i=2; i<MAXN; i++) {
        if (isPrime[i] && i & 1) {
            for (int j=i * 2; j<MAXN; j += i) isPrime[j] = 0;
            primes.pb(i);
            s.insert(i);
        }
    }
}

inline void Solve2 () {
    int a = -INF, b = -INF, c = -INF;
    vi diff, res;
    for (size_t i=0; i<primes.size(); i++) {
        if (primes[i] * 3 > x) break;
        else {
            diff.pb(x - primes[i] * 3);
            res.pb(primes[i]);
            a = primes[i];
        }
    }
    bool flag = 0;
    for (size_t i=diff.size() - 1; i>=0; i--) {
        for (int j=diff[i] / 2; j>=0; j--) {
            if (res[i] + j <= 10000000 && res[i] - j + diff[i] <= 10000000) {
                if (isPrime[res[i] + j] && isPrime[res[i] - j + diff[i]]) {
                    a = x - res[i] * 2 - diff[i], b = res[i] + j, c = res[i] - j + diff[i];
                    flag = 1;
                    break;
                }
            }
            else break;
        }
        if (flag) break;
    }
    cout << x << " = " << a << " + " << b << " + " << c << "\n";
}

inline void Solve1 () {
    int a = -INF, b = -INF;
    bool good = 0;
    for (size_t i=0; i<primes.size(); i++) {
        if (primes[i] > x / 2) break;
        if (s.count(x - primes[i])) {
            a = primes[i], b = x - primes[i];
            good = 1;
        }
    }
    if (!good) Solve2();
    else {
        // D("%d %d\n", a, b);
        cout << x << " = " << a << " + " << b << "\n";
    }
}

inline void Do_Test_Cases () {
    Sieve();
    while (TEST_CASES--) {
        cin >> x;
        if (isPrime[x]) cout << x << " = " << x << "\n";
        else {
            Solve1();
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
    Do_Test_Cases();
    return 0;
}