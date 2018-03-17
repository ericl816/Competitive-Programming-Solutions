#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXM 1000010
#define MAXN 200010
#define INF 0x3f3f3f3f
#define MOD 1000000007
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

/*
 * Solution involves BIT, bit tricks, line sweep, and coordinate compression
 */

struct BIT {
private:
	int N;
	vector<ll> tree;

public:
	BIT (int N) : N(N), tree(N + 1) { }

	void Update (int idx, ll val) {
		for (; idx<=N; idx += idx & -idx) tree[idx] += val;
	}
	
	void Update (int x, int y, ll val) {
		Update(x, val);
		Update(y + 1, -val);
	}

	ll Query (int idx) {
		ll sum = 0;
		for (; idx; idx -= idx & -idx) sum += tree[idx];
		return sum;
	}
};

BIT tree(MAXM);

inline pair<ll, ll> Return_Index (ll n, ll res1 = 1, ll res2 = 60) {
	while (n ^ 1) {
		if (n & 1) res1 += ((1ll << res2) - 1) << 1;
		res1++;
		n >>= 1;
		res2--;
	}
	return mp(res1, res1 + ((((1ll << res2) - 1)) << 2) + 1);
}

struct Events {
	int id;
	ll x, a, b, color;

	bool operator < (const Events &a) const {
		if (a.x ^ x) return x < a.x;
		return id < a.id;
	}
};

int N, Q, xidx, yidx;
ll x, y, v, r, c;
ll ans[MAXN];
vector<Events> events;
unordered_map<ll, int> xcompress, ycompress;
set<ll> xcoor, ycoor; // Note: The order does matter, hence unordered_set doesn't work

int main () {
	scan(N); scan(Q);
	for (int i=0; i<N; i++) {
		scan(x); scan(y); scan(v);
		events.pb((Events) {1, Return_Index(x).f, Return_Index(y).f, Return_Index(y).s, v});
		events.pb((Events) {2, Return_Index(x).s, Return_Index(y).f, Return_Index(y).s, -v});
		xcoor.insert(Return_Index(x).f);
		xcoor.insert(Return_Index(x).s);
		ycoor.insert(Return_Index(y).f);
		ycoor.insert(Return_Index(y).s);
	}
	for (int i=0; i<Q; i++) {
		scan(r); scan(c);
		events.pb((Events) {3, Return_Index(r).f, Return_Index(c).f, 0, i});
		xcoor.insert(Return_Index(r).f);
		ycoor.insert(Return_Index(c).f);
	}
	for (auto x : xcoor) xcompress[x] = ++xidx;
	for (auto y : ycoor) ycompress[y] = ++yidx;
	sort(events.begin(), events.end());
	for (size_t i=0; i<events.size(); i++) {
		Events &next = events[i];
		if (next.id == 3) ans[next.color] = tree.Query(ycompress[next.a]);
		else tree.Update(ycompress[next.a], ycompress[next.b], next.color);
	}
	for (int i=0; i<Q; i++) printf("%lld\n", ans[i]);
	return 0;
}