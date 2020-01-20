#include <bits/stdc++.h>
#define ll long long 
#define vi vector<int>
#define s size
#define pb push_back
#define f front
#define b back
#define MAXN 150010
#define limit 390
using namespace std;

int N, M, Q, L[MAXN], A[MAXN], op[MAXN], query, l, r, x, ans;
bool smallq[MAXN];
vi subs[MAXN], PSA[MAXN], bigq;

struct BITtree {
private:
	int N;
	vi BIT;

public:
	BITtree (int N) : N(N), BIT(N + 1) { }

	void Update (int idx, int val) {
		for (; idx <= N; idx += idx & -idx) BIT[idx] += val;
	}

	int Query (int idx) {
		int sum = 0;
		for (; idx > 0; idx -= idx & -idx) sum += BIT[idx];
		return sum;
	}

	void SmallUpdate (int idx) { 
		for (int i=0; i<subs[idx].s(); i++) Update(subs[idx][i], -A[subs[idx][(op[idx] + i) % subs[idx].s()]]);
		op[idx] = (op[idx] + subs[idx].s() - 1) % subs[idx].s();
		for (int i=0; i<subs[idx].s(); i++) Update(subs[idx][i], A[subs[idx][(op[idx] + i) % subs[idx].s()]]);
 	}

	void BigUpdate (int idx) { 
		op[idx] = (op[idx] + subs[idx].s() - 1) % subs[idx].s();
	}

	int SmallQuery (int a, int b) { 
		return Query(b) - Query(a - 1);
	}

	int BigQuery (int a, int b) { 
	  int sum;
		for (int i=0; i<bigq.s(); i++) {
		  int lo, hi, mid;
		  lo = 0;
		  hi = subs[bigq[i]].s() - 1;
			while (lo <= hi) {
				mid = (lo + hi) >> 1;
				if (subs[bigq[i]][mid] <= b) lo = mid + 1;
				else hi = mid - 1;
			}
			sum += PSA[bigq[i]][op[bigq[i]] + lo];
			lo = 0;
			hi = subs[bigq[i]].s() - 1;
			while (lo <= hi) {
				mid = (lo + hi) >> 1;
				if (subs[bigq[i]][mid] < a) lo = mid + 1;
				else hi = mid - 1;
			}
			sum -= PSA[bigq[i]][op[bigq[i]] + lo];
		}
		return sum;
	}
};

BITtree bit (MAXN);

int main () {
	scanf("%d %d %d", &N, &M, &Q);
	for (int i=0; i<N; i++) {
		scanf("%d", &L[i + 1]);
		subs[L[i + 1]].pb(i + 1);
	}
	for (int i=0; i<M; i++) {
		op[i + 1] = 0;
		smallq[i + 1] = (limit >= subs[i + 1].s()) ? 1 : 0;
		if (!smallq[i + 1]) { 
			bigq.pb(i + 1);
			PSA[i + 1].pb(0);
		}
	}
	for (int i=0; i<N; i++) {
		scanf("%d", &A[i + 1]);
		if (smallq[L[i + 1]]) bit.Update(i + 1, A[i + 1]);
	}
	for (int i=0; i<bigq.s(); i++) 
		for (int j=0; j<2; j++)
			for (int k=0; k<subs[bigq[i]].s(); k++) 
				PSA[bigq[i]].pb(A[subs[bigq[i]][k]] + PSA[bigq[i]].b());
	for (int i=0; i<Q; i++) {
		scanf("%d", &query);
		if (query == 1) {
			scanf("%d %d", &l, &r);
			printf("%d\n", bit.SmallQuery(l, r) + bit.BigQuery(l, r));
		}
		else if (query == 2) {
			scanf("%d", &x);
			if (smallq[x]) bit.SmallUpdate(x);
			else bit.BigUpdate(x);
		}
	}
}