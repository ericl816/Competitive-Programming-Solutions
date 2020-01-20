#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXN 110
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

int N, T, L, sum1, sum2;
int x[MAXN], t[MAXN];
int DP[2][MAXN];
vector<pii> queries[MAXN];

inline bool Cmp (pii &a, pii &b) {
	return a.f < b.f;
}

int main () {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> T;
	for (int i=1; i<=N; i++) {
		cin >> L;
		sum1 = sum2 = 0;
		for (int j=1; j<=L; j++) {
			cin >> t[j] >> x[j];
			sum1 += t[j];
			sum2 += x[j];
			queries[i].pb(mp(sum1, sum2));
		}
	}
	for (int i=1; i<=N; i++) {
		for (size_t j=0; j<queries[i].size(); j++) {
			pii &next = queries[i][j];
			for (int k=1; k<=T; k++) {
				DP[i & 1][k] = max(DP[i & 1][k - 1], DP[(i + 1) & 1][k]);
				if (k - next.f >= 0) {
					DP[i & 1][k] = max(DP[i & 1][k], DP[(i + 1) & 1][k - next.f] + next.s);
				}
			}
		}
	}
	cout << DP[N & 1][T] << "\n";
	return 0;
}