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

// This solution is based off of DP transitions and states (whether you take or not)
// Similar to Greedy for Pies, except it's wayyy easier

int N, V, S, T;
int DP[2][MAXN]; // DP[i][j] = ans at DP state i (take or not) and amount of time remaining
ll ans;
bool flag, flag1;
bool vis[MAXN];
vector<pair<int, pii> > queries;

inline bool Cmp (pair<int, pii> &a, pair<int, pii> &b) {
	return a.s.s < b.s.s;
}

int main () {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for (int i=1; i<=N; i++) {
		cin >> V >> S >> T;
		queries.pb(mp(V, mp(S, T)));
	}
	sort(queries.begin(), queries.end(), Cmp);
	for (int i=1; i<=N; i++) {
		for (int j=1; j<=MAXM; j++) {
			DP[i & 1][j] = max(DP[(i + 1) & 1][j], DP[i & 1][j - 1]);
			pair<int, pii> &next = queries[i];
			int v = next.f;
			int s = next.s.f;
			int t = next.s.s;
			if (j - s >= 0 && j <= t) {
				DP[i & 1][j] = max(DP[i & 1][j], DP[(i + 1) & 1][j - s] + v);
			}
		}
	}
	cout << DP[N & 1][MAXM] << "\n";
	return 0;
}
