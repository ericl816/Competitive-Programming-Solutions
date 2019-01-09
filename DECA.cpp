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
#ifdef DEBUG
    #define D(x...) printf(x)
#else
    #define D(x...)
#endif
using namespace std;

// Time Complexity: O((N + Q)log^2 * N)

int N, Q, op;
ll a, b, c, v;
ll A[MAXN];

struct BIT {
private:
    int N;
    vector<ll> bit1, bit2;

public:
    BIT(int N) : N(N), bit1(N + 1), bit2(N + 1) { }

    void Update (vector<ll> &bit, int idx, ll val) {
        for (; idx<=N; idx += idx & -idx) bit[idx] += val;
    }

    void Update (int x, int y, ll val) {
        Update(bit1, x, val);
        Update(bit1, y + 1, -val);
        Update(bit2, x, val * (x - 1));
        Update(bit2, y + 1, -val * y);
    }

    ll Query (vector<ll> &bit, int idx) {
        ll sum = 0;
        for (; idx; idx -= idx & -idx) sum += bit[idx];
        return sum;
    }

    ll Query (int x) {
        return Query(bit1, x) * x - Query(bit2, x);
    }

    ll Query (int x, int y) {
        return Query(y) - Query(x - 1);
    }
};

BIT tree(MAXN);

int main () {
    #ifdef NOT_DMOJ
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif // NOT_DMOJ
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> Q;
    for (int i=1; i<=N; i++) {
        cin >> A[i];
    }
    while (Q--) {
        cin >> op;
        if (op == 2) {
            cin >> v;
            cout << tree.Query(v, v) << "\n";
        }
        else {
            cin >> a >> b >> c;
            int ind1 = lower_bound(A + 1, A + N + 1, a) - A;
            int ind2 = lower_bound(A + 1, A + N + 1, b) - A;
            if (A[ind2] ^ b) ind2--;
            tree.Update(ind1, ind2, c);
        }
    }
    return 0;
}

/*
7 5
1 4 7 13 35 1000000000000000000 
2 3
1 1 4 10
2 2
1 1 100000000000000000 5
2 5

Ans:
0
10
5
*/

/* 
 * Look for:
 * the exact constraints (multiple sets are too slow for n=10^6 :( ) 
 * special cases (n=1?)
 * overflow (ll vs int?)
 * array bounds
 */