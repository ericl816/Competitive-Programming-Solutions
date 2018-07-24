#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
// #include <bits/stdc++.h>
#include "/Users/ericliu/Desktop/Competitive-Programming-Templates/stdc++.h"
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

// Question asks for the number of elements that satifsy this condition:s
// It is larger than all of its elements to its left in the array A
// NOTE: Elements at index 0 still count!
// Use a monoqueue and a BIT to solve this problem! :)

struct BIT {
private:
	int N;
	vi tree;

public:
	BIT (int N) : N(N), tree(N + 1) { }

	void Update (int idx, int val) {
		for (; idx<=MAXN; idx += idx & -idx) tree[idx] += val;
	}

	int Query (int idx) {
		int sum = 0;
		for (; idx; idx -= idx & -idx) sum += tree[idx];
		return sum;
	}
};

BIT tree(MAXN);

int N, Q, l, r;
int arr[MAXN], ans[MAXN];
mii ind; // For mapping
vector<pii> sub;
vector<pii> queries[MAXN];
deque<int> mq; // Monoqueue or monotonically-increasing stack

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
		cin >> arr[i];
		ind[arr[i]] = i; // Need to map to support the Fenwick tree operatinos
		sub.pb(mp(arr[i], i));
	}
	for (int i=0; i<Q; i++) {
		cin >> l >> r;
		queries[l].pb(mp(r, i));
	}
	for (int i=N; i>=1; i--) {
		while (!mq.empty() && mq.front() < arr[i]) {
			int curr = mq.front();
			tree.Update(ind[curr], -1);
			mq.pop_front();
		}
		mq.push_front(arr[i]);
		tree.Update(ind[mq.front()], 1);
		for (size_t j=0; j<queries[i].size(); j++) {
			pii &next = queries[i][j];
			ans[next.s] = tree.Query(next.f);
		}
	}
	for (int i=0; i<Q; i++) cout << ans[i] << "\n";
	return 0;
}