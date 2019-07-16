#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define ull unsigned long long
#define MAXM 510
#define MAXN 150010
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
#ifdef DEBUG
	#define D(x...) printf(x)
#else
	#define D(x...)
#endif
using namespace std;

int N, M, Q, L[MAXN], A[MAXN], op[MAXN], query, l, r, x, ans;
bool smallq[MAXN];
vi bigq;
vi subs[MAXN], PSA[MAXN];

struct BITtree {
private:
	int N;
	vi BIT;

public:
	BITtree (int N) : N(N), BIT(N + 1) { }

	inline void Update (int idx, int val) {
		for (; idx <= N; idx += idx & -idx) BIT[idx] += val;
	}

	inline int Query (int idx) {
		int sum = 0;
		for (; idx > 0; idx -= idx & -idx) sum += BIT[idx];
		return sum;
	}

	inline void SmallUpdate (int idx) { // Small Update => make sure to modulo
		for (size_t i=0; i<subs[idx].size(); i++) Update(subs[idx][i], -A[subs[idx][(op[idx] + i) % subs[idx].size()]]);
		op[idx] = (op[idx] + subs[idx].size() - 1) % subs[idx].size();
		for (size_t i=0; i<subs[idx].size(); i++) Update(subs[idx][i], A[subs[idx][(op[idx] + i) % subs[idx].size()]]);
 	}

	inline void BigUpdate (int idx) { // Big Update
		op[idx] = (op[idx] + subs[idx].size() - 1) % subs[idx].size();
	}

	inline int SmallQuery (int a, int b) { // Small Query
		return Query(b) - Query(a - 1);
	}

	inline int BigQuery (int a, int b) { // Big Query => upper_bound
		int sum = 0;
		for (size_t i=0; i<bigq.size(); i++) {
		  int lo = 0, hi = subs[bigq[i]].size() - 1;
			while (lo <= hi) {
				int mid = (lo + hi) >> 1;
				if (subs[bigq[i]][mid] <= b) lo = mid + 1;
				else hi = mid - 1;
			}
			sum += PSA[bigq[i]][op[bigq[i]] + lo];
			lo = 0;
			hi = subs[bigq[i]].size() - 1;
			while (lo <= hi) {
				int mid = (lo + hi) >> 1;
				if (subs[bigq[i]][mid] < a) lo = mid + 1;
				else hi = mid - 1;
			}
			sum -= PSA[bigq[i]][op[bigq[i]] + lo];
		}
		return sum;
	}
};

BITtree bit (MAXN);

int main (int argc, char const *argv[]) {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	scan(N); scan(M); scan(Q);
	for (int i=1; i<=N; i++) {
		scan(L[i]);
		subs[L[i]].pb(i);
	}
	for (int i=1; i<=M; i++) {
		op[i] = 0;
		smallq[i] = (MAXM >= subs[i].size()) ? 1 : 0;
		if (!smallq[i]) { 
			bigq.pb(i);
			PSA[i].pb(0);
		}
	}
	for (int i=1; i<=N; i++) {
		scan(A[i]);
		if (smallq[L[i]]) bit.Update(i, A[i]);
	}
	for (size_t i=0; i<bigq.size(); i++) {
		for (int j=0; j<2; j++) {
			for (size_t k=0; k<subs[bigq[i]].size(); k++) {
				PSA[bigq[i]].pb(A[subs[bigq[i]][k]] + PSA[bigq[i]].back());
			}
		}
	}
	for (int i=0; i<Q; i++) {
		scan(query);
		if (query == 1) {
			scan(l); scan(r);
			printf("%d\n", bit.SmallQuery(l, r) + bit.BigQuery(l, r));
		}
		else if (query == 2) {
			scan(x);
			if (smallq[x]) bit.SmallUpdate(x);
			else bit.BigUpdate(x);
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