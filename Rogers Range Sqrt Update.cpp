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

struct BIT {
private:
    int N;
    vector<ll> tree;

public:
    BIT(int N) : N(N), tree(N + 1) { }

    inline void Update (int idx, int val) {
		for (; idx<=N; idx += idx & -idx) tree[idx] += val;
	}

	inline ll Query (int idx) {
		ll sum = 0;
		for (; idx; idx -= idx & -idx) sum += tree[idx];
		return sum;
	}

    inline ll Query (int x, int y) {
        return Query(y) - Query(x - 1);
    }
};

BIT tree(MAXN);

int N, M, x, l, r;
int a[MAXN];
set<int> cheese;

int main (int argc, char const *argv[]) {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for (int i=1; i<=N; i++) {
		cin >> a[i];
		if (a[i] > 1) cheese.insert(i);
		tree.Update(i, a[i]);
	}
	cin >> M;
	for (int i=0; i<M; i++) {
		cin >> x >> l >> r;
		if (x == 1) cout << tree.Query(l, r) << "\n";
		else {
			// Need to change value of ai from i=1,2,3...N to floor(sqrt(ai))
			set<int>::iterator it = cheese.lower_bound(l);
			for (it; it!=cheese.end() && *it<=r;) {
				ll val = (ll) sqrt(a[*it]);
				tree.Update(*it, val - a[*it]);
				a[*it] = val;
				// Constant optimize
				if (a[*it] <= 1) cheese.erase(it++);
				else it++;
			}
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