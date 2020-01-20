#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXM 15010
#define MAXN 30010
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define EPS 1e-9
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
using namespace std;

int N;
ll x;

template <typename T>
struct BIT {
private:
    int N;
    vector<T> tree;

public:
    BIT (int N) : N(N), tree(N + 1) { }

    inline void Update (int idx, int val) {
        for (; idx<=N; idx += idx & -idx) tree[idx] += val;
    }

    inline T Query (int idx) {
        T sum = 0;
        for (; idx; idx -= idx & -idx) sum += tree[idx];
        return sum;
    }

    inline T Query (int a, int b) {
        return Query(b) - Query(a - 1);
    }

};

BIT<ll> tree1(MAXN), tree2(MAXN), tree3(MAXN);

int main () {
    #ifdef NOT_DMOJ
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif // NOT_DMOJ
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    while (N--) {
        cin >> x;
        tree1.Update(x + MAXM, 1LL);
        tree2.Update(x + MAXM, 1LL * x);
        tree3.Update(x + MAXM, 1LL * x * x);
        long double lo = -15000.0, hi = 15000.0, mid = 0;
        // cout << fixed << setprecision(3) << lo << " " << hi << endl;
        while (hi - lo >= EPS) {
            mid = (lo + hi) / 2.0;
            // cout << mid << endl;
            int lhs = (int) floor(mid) + MAXM, rhs = (int) ceil(mid) + MAXM;
            // cout << fixed << setprecision(3) << lhs << " " << rhs << "\n";
            long double a = (tree1.Query(1, lhs) - tree1.Query(rhs, MAXN));
            long double b = 2 * (tree2.Query(rhs, MAXN) - tree2.Query(1, lhs));
            long double c = (tree3.Query(1, lhs) - tree3.Query(rhs, MAXN));
            // cout << fixed << setprecision(3) << "WHY: " << a << " " << b << " " << c << "\n";
            if (a * mid * mid + b * mid + c < 0) lo = mid;
            else hi = mid;
        }
        cout << fixed << setprecision(10) << mid << "\n";
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