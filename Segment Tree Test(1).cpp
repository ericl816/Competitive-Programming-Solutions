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
#define INF 2147483647
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

int N, M, x, y, ans;
char op;
int minn[MAXN], gcd[MAXN], num[MAXN];

inline void Build () {
    for(int i=N - 1; i; i--) {
        minn[i] = min(minn[i << 1], minn[i << 1 | 1]);
        gcd[i] = GCD(gcd[i << 1], gcd[i << 1 | 1]);
        num[i] = (gcd[i] == gcd[i << 1] ? num[i << 1] : 0) + (gcd[i] == gcd[i << 1 | 1] ? num[i << 1 | 1] : 0);
    }
}

inline void Update(int idx, int val) {
    int idx1 = idx, idx2 = idx;
    idx1 += N, idx2 += N, idx += N;
    for (gcd[idx1]=val; idx1>1; idx1 >>= 1) gcd[idx1 >> 1] = GCD(gcd[idx1], gcd[idx1 ^ 1]);
    for (num[idx2]=1; idx2>1; idx2 >>= 1) num[idx2 >> 1] = (gcd[idx2 >> 1] == gcd[idx2] ? num[idx2] : 0) + (gcd[idx2 >> 1] == gcd[idx2 ^ 1] ? num[idx2 ^ 1] : 0);
    for (minn[idx]=val; idx>1; idx >>= 1) minn[idx >> 1] = min(minn[idx], minn[idx ^ 1]);
}

inline int QueryGCD (int l, int r) {
    int res = 0;
    for (l += N, r += N; l<r; l >>= 1, r >>= 1) {
        if (l & 1) res = GCD(res, gcd[l++]);
        if (r & 1) res = GCD(res, gcd[--r]);
    }
    return res;
}

inline int QueryMin (int l, int r) {
    int res = INF;
    for (l += N, r += N; l<r; l >>= 1, r >>= 1) {
        if (l & 1) res = min(res, minn[l++]);
        if (r & 1) res = min(res, minn[--r]);
    }
    return res;
}

inline int QueryNum (int l, int r, int val) {
    int res = 0;
    for (l += N, r += N; l<r; l >>= 1, r >>= 1) {
        if (l & 1) res += (val == gcd[l] ? num[l++] : 0);
        if (r & 1) res += (val == gcd[--r] ? num[r] : 0);
    }
    return res;
}

int main (int argc, char const *argv[]) {
    #ifdef NOT_DMOJ
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif // NOT_DMOJ
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for (int i=0; i<N; i++) {
        cin >> minn[i + N];
        gcd[i + N] = minn[i + N];
        num[i + N] = 1;
    }
    Build();
    while (M--) {
        cin >> op >> x >> y;
        --x;
        if (op == 'M') cout << QueryMin(x, y) << '\n';
        else if (op =='G') cout << QueryGCD(x, y) << '\n';
        else if (op == 'Q') cout << QueryNum(x, y, QueryGCD(x, y)) << '\n';
        else Update(x, y);
    }
    return 0;
}

/* 
 * Look for:
 * the exact constraints (multiple sets are too slow for n=10^6 :( ) 
 * special cases (n=1?)
 * overflow (ll vs int?)
 * array bounds
 */