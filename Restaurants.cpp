#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXN 1000005
#define INF 0x3f3f3f3f
#define min(a, b) (a) < (b) ? (a) : (b)
#define max(a, b) (a) < (b) ? (b) : (a)
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define mii map<int, int>
#define umii unordered_map<int, int>
#define println cout << "\n";
#ifdef DEBUG
    #define D(x...) printf(x)
#else
    #define D(x...)
#endif
using namespace std;

int N, T, K, V;
ll cnt;
set<int> ss;
bool flag[MAXN];

struct BIT {
private:
    int N;
    vector<ll> tree;

public:
    BIT (int N) : N(N), tree(N + 1) { }

    inline void Update (int idx, int val) {
        for (; idx<=MAXN; idx += idx &- idx) tree[idx] += val;
    }

    inline ll Query (int idx) {
        ll sum = 0;
        for (; idx; idx -= idx &- idx) sum += tree[idx];
        return sum;
    }
};

BIT tree(MAXN);

int main (int argc, char const *argv[]) {
    #ifdef NOT_DMOJ
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif // NOT_DMOJ
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> T >> K >> V;
    for (int i=1; i<=N; i++) ss.insert(i);
    for (int i=0, x; i<V; i++) {
        cin >> x;
        flag[x] = 1;
        ss.erase(x);
    }
    for (int i=1; i<=N; i++) tree.Update(i, flag[i]);
    for(int i=0; i<=N - T; i++) {
        while (tree.Query(i + T) - tree.Query(i) < K) {
            auto it = prev(ss.upper_bound(i + T));
            ++cnt;
            tree.Update(*it, 1);
            ss.erase(it);
        }
    }
    cout << cnt << "\n";
    return 0;
}

/* 
 * Look for:
 * the exact constraints (multiple sets are too slow for n=10^6 :( ) 
 * special cases (n=1?)
 * overflow (ll vs int?)
 * array bounds
 */