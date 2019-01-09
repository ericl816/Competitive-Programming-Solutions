#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define ull unsigned long long
#define MAXM 1000000010
#define MAXN 100010
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

int N, Q, op, l, r;
int a[MAXN];
set<ll> s;

struct BIT {
private:
    int N;
    vi tree;

public:
    BIT (int N) : N(N), tree(N + 1) { }

    inline void Update (int idx, int val) {
        for (; idx<=MAXN; idx += idx & -idx) tree[idx] += val;
    }

    inline ll Query (int idx) {
        ll sum = 0LL;
        for (; idx; idx -= idx & -idx) sum += tree[idx];
        return sum;
    }

    inline ll Query (int x, int y) {
        return Query(y) - Query(x - 1);
    }
};

BIT tree(MAXN);

bool prime[MAXN];

void Sieve (int n) {
    memset(prime, 1, sizeof(prime));
    prime[1] = 0;
    for (int i=2; i*i<=n; i++) if (prime[i]) for (int j=i*i; j<=n; j+=i) prime[j] = 0;
}

int main (int argc, char const *argv[]) {
    #ifdef NOT_DMOJ
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif // NOT_DMOJ
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> Q;
    Sieve(MAXN);
    for (int i=1; i * i<=MAXM; i++) {
        if (prime[i]) s.insert(i * i);
    }
    for (int i=1; i<=N; i++) {
        cin >> a[i];
        if (s.count(a[i])) tree.Update(i, 1);
    }
    while (Q--) {
        cin >> op >> l >> r;
        if (op == 1) cout << tree.Query(l, r) << "\n";
        else {
            tree.Update(l, s.count(r) - s.count(a[l]));
            a[l] = r;
        }
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