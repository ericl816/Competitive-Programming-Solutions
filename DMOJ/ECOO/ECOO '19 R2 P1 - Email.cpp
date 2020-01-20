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

int N;
string S;

inline void Do_Test_Cases () {
    while (TEST_CASES--) {
        // Put code here.
        cin >> N;
        set<string> setss;
        for (int i=0; i<N; i++) {
            cin >> S;
            string s = "";
            for (auto j : S) s += tolower(j);
            size_t ind = s.find('@'), ind1 = s.find('+');
            string sss = "";
            if (ind != string::npos) {
                for (size_t j=0; j<ind; j++) {
                    if (s[j] == '.') continue;
                    sss += s[j];
                }
                for (size_t j=ind; j<s.size(); j++) sss += s[j];
            }
            string q = "", q1 = "", ans = "";
            ind = sss.find('@'), ind1 = sss.find('+');
            if (ind1 != string::npos) {
                if (ind1 == 1) q = sss[0];
                else q = sss.substr(0, ind1);
                if (ind != string::npos) q1 = sss.substr(ind);
                ans = q + q1;
            }
            else ans = sss;
            setss.insert(ans);
        }
        cout << setss.size() << "\n";
    }
}

int main () {
    #ifdef NOT_DMOJ
    freopen("Desktop/ECOO_2019/Round_2/DATA11.txt", "r", stdin);
    freopen("Desktop/ECOO_2019/Round_2/DATA11out.txt", "w", stdout);
    #endif // NOT_DMOJ
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Do_Test_Cases();
    return 0;
}

/*
3
foo@bar.com
fO.o+baz123@bAR.com
foo@bar..com
3
c++@foo.com
c...@Foo.com
.c+c@FOO.COM
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