#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define ull unsigned long long
#define MAXN 100010
#define INF 0x3f3f3f3f
#define MOD 1000000007
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

int N, Q, op, l, r, v;

struct BIT {
private:
    int N;
    vector<ll> bit1, bit2;

public:
    BIT(int N) : N(N), bit1(N + 1), bit2(N + 1) { }

    void Update (vector<ll> &bit, int idx, int val) {
        for (; idx<=N; idx += idx & -idx) bit[idx] += val;
    }

    void Update (int x, int y, int val) {
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

int main (int argc, char const *argv[]) {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> Q;
	while(Q--) {
		cin >> op >> l;
		if (op == 2) tree.Update(1, N, l);
		else {
			cin >> r;
			cout << tree.Query(l, r) << "\n";
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