#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define ull unsigned long long
#define MAXN 201
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

int x;
string fib[MAXN];

inline string add (string s1, string s2) {
    string t1,t2; char c1=48;
    int d = s1.length()-s2.length();
    for (int i=0; i<(d<0?-d:d); i++)
        (d<0?s1:s2)="0"+(d<0?s1:s2);
    for (int i=s1.length()-1; i>=0; i--) {
        t1 = to_string(s1[i]+s2[i]+c1-144);
        c1 = (t1.length()<2?48:t1[0]);
        t2 = (t1.length()<2?t1[0]:t1[1])+t2;
    }
    return (c1!=48?c1+t2:t2);
}

int main (int argc, char const *argv[]) {
    #ifdef NOT_DMOJ
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif // NOT_DMOJ
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    fib[1] = fib[2] = "1";
    for (int i=3; i<=200; i++) fib[i] = add(fib[i - 1], fib[i - 2]);
    while (cin >> x) {
        if (!x) break;
        cout << fib[x] << "\n";
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