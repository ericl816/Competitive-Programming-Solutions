#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXM 1010
#define MAXN 10010
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

// TBH, this solution is both DP and greedy...

int N, V, S, T;
vector<pii> queries[MAXN];
int DP[MAXN];

int main () {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for (int i=0; i<N; i++) {
		cin >> V >> S >> T;
		queries[T].pb(mp(V, S));
	}
	for (int i=1; i<=MAXM; i++) {
		DP[i] = DP[i - 1];
		for (size_t j=0; j<queries[i].size(); j++) {
			pii &next = queries[i][j];
			for (int k=i; k>=next.s; k--) {
				if (DP[k] <= DP[k - next.s] + next.f) {
					DP[k] = DP[k - next.s] + next.f;
				}
			}
		}
	}
	cout << DP[MAXM] << "\n";
	return 0;
}