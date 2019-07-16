#include <bits/stdc++.h>
#define ll long long
#define MAXN 100010
#define INF 0x3f3f3f3f
#define min(a, b) (a) < (b) ? (a) : (b)
#define max(a, b) (a) < (b) ? (b) : (a)
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
        BIT(int N) : N(N), tree(N + 1) { }

	void Update(int idx, int val) {
		for (; idx<=MAXN; idx += idx & -idx) tree[idx] += val;
	}

	int Query(int idx) {
		int sum = 0;
		for (; idx; idx -= idx & -idx) sum += tree[idx];
		return sum;
	}

	int Query(int a, int b) {
		return Query(b) - Query(a - 1);
	}
};

int N, x, lo, hi, arr[MAXN];
BIT tree(MAXN);

int main () {
	scanf("%d", &N);
	for (int i=1; i<=N; i++) {
		scanf("%d", &x);
		arr[x] = i;
		tree.Update(i, 1);
	}
	lo = 1, hi = N;
	for (int i=1; i<=N; i++) {
		if (i & 1) {
			tree.Update(arr[lo], -1);
			printf("%d\n", tree.Query(1, arr[lo]));
			lo++;
		}
		else {
			tree.Update(arr[hi], -1);
			printf("%d\n", tree.Query(arr[hi], N));
			hi--;
		}
	}
	return 0;
}
