#include <bits/stdc++.h>
#define ll long long 
#define MAXN 100010
#define SIZE 316
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define mii map<int, int>
#define umii unordered_map<int, int>
using namespace std;

struct Array {
	int l, r, idx;
};

inline bool BlkCompare (Array &a, Array &b) {
  return (a.l / SIZE ^ b.l / SIZE) ? a.l < b.l : a.r < b.r;
}

int N, Q, lidx = 1, ridx, A[MAXN];
ll ans[MAXN], arr[MAXN], num;
vector<Array> vec;
pii seq[MAXN];
//umii arr;

struct RMQ {
private:
  int N;
  vi BIT;

public:
  RMQ(int N) : N(N), BIT(N) { }
  
  void Update (int idx, int val) {
		for (; idx<=MAXN; idx += idx & -idx) BIT[idx] += val;
  }

  ll Query (int idx) {
		ll sum = 0;
		for (; idx>0; idx -= idx & -idx) sum += BIT[idx];
		return sum;
  }
};

RMQ tree(MAXN);

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i=1; i<=N; i++) {
		cin >> A[i];
		seq[i] = mp(A[i], i);
	}
	sort(seq + 1, seq + N + 1);
	for (int i=1; i<=N; i++) arr[seq[i].s] = i;
	cin >> Q;
	for (int a=0, i, j; a<Q; a++) {
		cin >> i >> j;
		vec.pb((Array) {i, j, a});
	}
	sort(vec.begin(), vec.end(), BlkCompare); 
	for (int i=0; i<vec.size(); i++) {
		Array &next = vec[i];
		while (lidx > next.l) {
			lidx--;
			num += tree.Query(arr[lidx] - 1);
			tree.Update(arr[lidx], 1);
		}
		while (lidx < next.l) {
			num -= tree.Query(arr[lidx] - 1);
			tree.Update(arr[lidx], -1);
			lidx++;
		}
		while (ridx > next.r) {
			num -= ridx - lidx + 1 - tree.Query(arr[ridx]);
			tree.Update(arr[ridx], -1);
			ridx--;
		}
		while (ridx < next.r) {
			ridx++;
			num += ridx - lidx - tree.Query(arr[ridx]);
			tree.Update(arr[ridx], 1);
		}
		ans[next.idx] = num;
	}
	for (int i=0; i<Q; i++) cout << ans[i] << "\n";
	return 0;
}
