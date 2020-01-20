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
int N, a, minn, prevv, curr;
vi v;

inline void Do_Test_Cases () {
    while (TEST_CASES--) {
        cin >> N;
        minn = prevv = curr = 0;
        v.clear();
        for (int i=0, a; i<N; i++) {
            cin >> a;
            v.pb(a);
        }
        for (int i=N; i>=2; i--) {
            for (int j=0; j<N; j++) {
                if (v[j] == i) prevv = j;
                if (v[j] == i - 1) curr = j;
            }
            // D("%d %d\n", prevv, curr);
            if (curr > prevv) {
                minn += curr;
                int val = v[curr];
                v.erase(v.begin() + curr);
                v.insert(v.begin(), val);
            }
        }
        cout << minn << "\n";
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
3, 5, 1, 4, 2

1, 3, 5, 4, 2


*/