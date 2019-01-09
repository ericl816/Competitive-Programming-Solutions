#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define ull unsigned long long
#define MAXN 200010
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
#define DEBUG 1
#ifdef DEBUG
    #define D(x...) printf(x)
#else
    #define D(x...)
#endif
using namespace std;

inline int GCD (int a, int b) { return b == 0 ? a : GCD(b, a % b); }
inline int LCM (int a, int b) { return a * b / GCD(a, b); }
inline ll PowMod (ll a, ll b, ll MOD) { ll val = 1; while (b) { if (b & 1) val = (val * a) % MOD; a = (a * a) % MOD; b >>= 1; } return val; }

// Use a Seg Tree of vectors and use binary search

int N, Q, a, b, q;
int A[MAXN];
vector<ll> elems[MAXN << 2], prefix_sum[MAXN << 2];
ll PSA[MAXN];

inline void Build (int idx, int l, int r) {
    if (l == r) {
        elems[idx].pb(A[l]);
        prefix_sum[idx].pb(A[l]);
    }
    else {
        int mid = (l + r) >> 1;
        Build(idx << 1, l, mid);
        Build(idx << 1 | 1, mid + 1, r);
        merge(elems[idx << 1].begin(), elems[idx << 1].end(), elems[idx << 1 | 1].begin(), elems[idx << 1 | 1].end(), back_inserter(elems[idx]));
        copy(elems[idx].begin(), elems[idx].end(), back_inserter(prefix_sum[idx]));
        for (int i=1; i<prefix_sum[idx].size(); i++) prefix_sum[idx][i] += prefix_sum[idx][i - 1];
    }
}

inline ll Query (int idx, int l, int r, int left, int right, int val) {
    if (right < l || r < left) return 0;
    if (left <= l && r <= right) {
        int ind = lower_bound(elems[idx].begin(), elems[idx].end(), val) - elems[idx].begin();
        return prefix_sum[idx].back() - (ind ? prefix_sum[idx][ind - 1] : 0);
    }
    int mid = (l + r) >> 1;
    return Query(idx << 1, l, mid, left, right, val) + Query(idx << 1 | 1, mid + 1, r, left, right, val);
}

int main() {
   #ifdef NOT_DMOJ
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif // NOT_DMOJ
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> Q;
    for (int i=0; i<N; i++) cin >> A[i];
    PSA[0] = A[0];
    for (int i=1; i<N; i++) PSA[i] = PSA[i - 1] + A[i];
    Build(1, 0, N - 1);
    while (Q--) {
        cin >> a >> b >> q;
        --a, --b;
        ll sum = PSA[b] - PSA[a - 1], l = sum - Query(1, 0, N - 1, a, b, q);
        cout << (sum - 2 * l) << '\n';
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