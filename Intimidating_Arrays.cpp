#include <bits/stdc++.h>
#define ll long long
#define MAXN 1000010
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define umii unordered_map<int, int>
#define mii map<int, int>
using namespace std;

int N, Q, l, r, arr[MAXN], ans[MAXN];
vector<pii> sub, perm[MAXN];
umii ind;
deque<int> mq;

struct BIT {
private:
	int N;
	vi tree;

public:
	BIT(int N) : N(N), tree(N + 1) { } 

	void Update (int idx, int val) {
		for (; idx<=MAXN; idx += idx & -idx) tree[idx] += val;
	}

	int Query (int idx) {
		int sum = 0;
		for (; idx; idx -= idx & -idx) {
			sum += tree[idx];
		}
		return sum;
	}

	int Query (int a, int b) {
		return Query(b) - Query(a - 1);
	}
};

BIT tree(MAXN);

bool Compare (pii &a, pii &b) {
	if (a.f == b.f) return a.s < b.s;
	return a.f < b.f;
}

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> Q;
	for (int i=1; i<=N; i++) {
		cin >> arr[i];
		ind[arr[i]] = i;
		sub.pb(mp(arr[i], i));
	}
	for (int i=0; i<Q; i++) {
		cin >> l >> r;
		perm[l].pb(mp(r, i));
	}
	for (int i=N; i>0; i--) {
		while (!mq.empty() && mq.front() < arr[i]) {
			int curr = mq.front();
			tree.Update(ind[curr], -1);
			mq.pop_front();
		}
		mq.push_front(arr[i]);
		tree.Update(ind[mq.front()], 1);
		for (size_t j=0; j<perm[i].size(); j++) {
			pii &next = perm[i][j];
			ans[next.s] = tree.Query(next.f);
		}
	}
	for (int i=0; i<Q; i++) cout << ans[i] << "\n";
	return 0;
}