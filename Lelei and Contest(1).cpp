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

// Using Fermat's Little Theorem and Pascal's Binomial Expansion, the query: (A[l]^M + A[l + 1]^M + ... + A[r]^M) % M becomes (A[l] + A[l + 1] + ... + A[r]) % M

int N, M, Q, op, l, r, x;
ll a;

struct BIT {
private:
    int N;
    vector<ull> bit1, bit2;

public:
    BIT(int N) : N(N), bit1(N + 1), bit2(N + 1) { }

    void Update (vector<ull> &bit, int idx, ull val) {
        for (; idx<=N; idx += idx & -idx) bit[idx] += val;
    }

    void Update (int x, int y, ull val) {
        Update(bit1, x, val);
        Update(bit1, y + 1, -val);
        Update(bit2, x, val * (x - 1));
        Update(bit2, y + 1, -val * y);
    }

    ull Query (vector<ull> &bit, int idx) {
        ll sum = 0;
        for (; idx; idx -= idx & -idx) sum += bit[idx];
        return sum;
    }

    ull Query (int x) {
        return Query(bit1, x) * x - Query(bit2, x);
    }

    ull Query (int x, int y) {
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
	cin >> M >> N >> Q;
	for (int i=1; i<=N; i++) {
        cin >> a;
        tree.Update(i, i, a);
    }
	while (Q--) {
		cin >> op;
		if (op == 1) {
			cin >> l >> r >> x;
			tree.Update(l, r, x);
		}
		else {
			cin >> l >> r;
			cout << (tree.Query(l, r) % M) << "\n";
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