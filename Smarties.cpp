#include <bits/stdc++.h>
#define MAXN 100010
#define MAXM 1000010
#define ll long long
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define umii unordered_map<int, int>
#define mii map<int, int>
using namespace std;

int N, K, freq, l, r, F[MAXN], pointer[MAXM];
ll num;
umii cnt;

struct BIT {
private:
	int N;
	vi tree;

public:
	BIT (int N) : N(N), tree(N + 1) { }

	void Update (int idx, int val) {
		for (; idx<=MAXN; idx += idx & -idx) tree[idx] += val;
	}

	ll Query (int idx) {
		ll sum = 0;
		for (; idx; idx -= idx & -idx) sum += tree[idx];
		return sum;
	}
};

BIT tree(MAXN);

inline int BS (int lo, int hi, int target) {
	while (lo <= hi) {
		int mid = (lo + hi) >> 1;
		if (target <= tree.Query(mid)) lo = mid + 1;
		else hi = mid - 1;
	}
	return hi;
}

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> K;
	for (int i=1; i<=N; i++) cin >> F[i];
	for (int i=1; i<=N; i++) {
		tree.Update(pointer[F[i]] + 1, 1);
		tree.Update(i + 1, -1);
		pointer[F[i]] = i;
		l = 1;
		r = i;
		num += BS(l, r, K);
	}
	/*
	for (r; r<N; ) {
	  	if (freq < K) if (++cnt[F[r++]] == 1) freq++; // Is contiguous subarray -> increase counter
	  	if (K <= freq) {
	  		if (--cnt[F[l++]] == 0) freq--; // Not contiguous -> decrease counter
	  		num += (ll) (N - r + 1); 
	  	}
  	}
  	*/
	cout << num << "\n";
	return 0;
}