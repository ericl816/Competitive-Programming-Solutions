#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXN 1000010
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
#define DEBUG 1
#ifdef DEBUG
    #define D(x...) printf(x)
#else
    #define D(x...)
#endif
using namespace std;

int N, Q, op, l, r, a;

template<typename T>
struct QuadBIT {
private:
    int N;
    T *tree[3];

public:
    QuadBIT (int n) {
        N = n;
        for (int i=0; i<3; i++) {
            tree[i] = (T*) malloc(n * sizeof(T));
            memset(tree[i], 0, n * sizeof(T));
        }
    }
    
    inline void Upd (int idx, int x, T val) {
        for (; x<=N; x += x & -x) tree[idx][x] += val;
    }

    inline void Update (int x, int y, T val) {
        int l = x - 1, r = y - x + 1;
        Upd(2, x, val);
        Upd(2, y + 1, -val);
        Upd(1, x, val * ((T) 1 - (T) 2 * (T) l));
        Upd(1, y + 1, -val * ((T) 1 - (T) 2 * (T) l));
        Upd(0, x, val * ((T) l * (T) l - (T) l));
        Upd(0, y + 1, -val * ((T) l * (T) l - (T) l));
        Upd(0, y + 1, val * ((T) r * (T) r + (T) r));
    }

    inline T Qry (int idx, int x) {
        T sum = 0;
        for (; x; x -= x & -x) sum += tree[idx][x];
        return sum;
    }

    inline T Query (int x) {
        return (Qry(2, x) * (T) x * (T) x + Qry(1, x) * (T) x + Qry(0, x)) / (T) 2;
    }

    inline T Query (int x, int y) {
        return Query(y) - Query(x - 1);
    }
};

QuadBIT<ll> tree(MAXN);

int main () {
    #ifdef NOT_DMOJ
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif // NOT_DMOJ
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> Q;
    while (Q--) {
        cin >> op >> l >> r;
        if (op == 2) cout << tree.Query(l, r) << "\n";
        else {
            cin >> a;
            tree.Update(l, r, a);
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