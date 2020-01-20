#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define MAXN 200010
#define INF 0x3f3f3f3f
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define umii unordered_map<int, int>
#define mii map<int, int>
using namespace std;

struct BIT {
private:
	int N;
	vi tree;

public:
	BIT (int N) : N(N), tree(N + 1) { }

	void Update (int idx, int val) {
		for (; idx<=N; idx += idx & -idx) tree[idx] += val;
	}

	ll Query (int idx) {
		ll sum = 0;
		for (; idx; idx -= idx & -idx) sum += tree[idx];
		return sum;
	}
};

int N, X, x, y;
ll ans;
BIT tree(MAXN << 1);
long double ang[MAXN << 1];
long double deltay, deltax, theta1, theta2;
vector<pair<long double, long double>> loc;
pii query[MAXN];

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> X;
	for (int i=0; i<N; i++) {
		cin >> x >> y;
		theta1 = atan2(y, x);
		theta2 = atan2(y, X - x);
		ang[i << 1] = theta1;
		ang[i << 1 | 1] = theta2;
		loc.pb(mp(theta1, theta2));
	}
	sort(ang, ang + (N << 1));
	for (int i=0; i<N; i++) query[i] = mp((N << 1) - (lower_bound(ang, ang + (N << 1), loc[i].f) - ang), (N << 1) - (lower_bound(ang, ang + (N << 1), loc[i].s) - ang));
	sort(query, query + N);
	for (int i=0; i<N; i++) {
		ans += tree.Query(query[i].s) * tree.Query(query[i].s);
		tree.Update(query[i].s, 1);
	}
	cout << ans << endl;
	return 0;
}