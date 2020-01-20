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
using namespace std;

int N, Q, op, a, v, l, r;
ll prevans, ans;
ll cost[MAXN];
pair<ll, ll> segmin[MAXN << 1], segmax[MAXN << 1];

inline pair<ll, ll> maxPair (pair<ll, ll> &a, pair<ll, ll> &b) {
    ll c[4] = {a.f, a.s, b.f, b.s};
    sort(c, c + 4);
    pair<ll, ll> res = mp(c[2], c[3]);
    return res;
}

inline pair<ll, ll> minPair (pair<ll, ll> &a, pair<ll, ll> &b) {
    ll c[4] = {a.f, a.s, b.f, b.s};
    sort(c, c + 4);
    pair<ll, ll> res = mp(c[0], c[1]);
    return res;
}

inline void maxsegUpdate (int idx, int val) {
    idx += N - 1;
    segmax[idx] = mp(val, -INF);
    for (int i=idx >> 1; i; i >>= 1) segmax[i] = maxPair(segmax[i << 1], segmax[i << 1 | 1]);
}

inline void minsegUpdate (int idx, int val) {
    idx += N - 1;
    segmin[idx] = mp(val, INF);
    for (int i=idx >> 1; i; i >>= 1) segmin[i] = minPair(segmin[i << 1], segmin[i << 1 | 1]);
}

inline ll maxsegQuery (int l, int r, int idx = 1) {
	l += N - 1;
	r += N - 1;
	pair<ll, ll> ans = mp(-INF, -INF);
	while (l <= r) {
		if (l & 1) {
			ans = maxPair(ans, segmax[l]);
			l++;
		}
		if (!(r & 1)) {
			ans = maxPair(ans, segmax[r]);
			r--;
		}
		l >>= 1;
		r >>= 1;
	}
	return ans.f + ans.s;
}

inline ll minsegQuery (int l, int r, int idx = 1) {
	l += N - 1;
	r += N - 1;
	pair<ll, ll> ans = mp(INF, INF);
	while (l <= r) {
		if (l & 1) {
			ans = minPair(ans, segmin[l]);
			l++;
		}
		if (!(r & 1)) {
			ans = minPair(ans, segmin[r]);
			r--;
		}
		l >>= 1;
		r >>= 1;
	}
    return ans.f + ans.s;
}

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
		cin >> cost[i];
		segmin[i + N - 1] = mp(cost[i], INF);
		segmax[i + N - 1] = mp(cost[i], -INF);
	}
	for (int i=N - 1; i>0; i--) {
	    segmin[i] = minPair(segmin[i << 1], segmin[i << 1 | 1]);
	    segmax[i] = maxPair(segmax[i << 1], segmax[i << 1 | 1]);
	}
	double size = sqrt(N);
	for (int i=0; i<Q; i++) {
	    cin >> op;
	    if (op == 1) {
	        cin >> a >> v;
	        a ^= prevans;
	        v ^= prevans;
	        minsegUpdate(a, v);
	        maxsegUpdate(a, v);
	    }
	    else if (op == 2) {
	        cin >> l >> r;
	        l ^= prevans;
	        r ^= prevans;
	        l *= size;
	        l = l - size + 1;
	        r *= size;
	        ans = minsegQuery(l, r);
	        cout << ans << "\n";
	    }
	    else {
	        cin >> l >> r;
	        l ^= prevans;
	        r ^= prevans;
	        l *= size;
	        l = l - size + 1;
	        r *= size;
	        ans = maxsegQuery(l, r);
	        cout << ans << "\n";
	    }
	    prevans = ans;
	}
	return 0;
}