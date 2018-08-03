#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXM 20
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
#ifdef DEBUG
	#define D(x...) printf(x)
#else
	#define D(x...)
#endif
using namespace std;

int T = 5, ans;
string s, op;
int dist[MAXM][MAXM];
char grid[MAXM][MAXM];

int main () {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	while (T--) {
		memset(dist, INF, sizeof(dist));
		ans = 0;
		for (int i=0; i<10; i++) {
			cin >> s;
			for (int j=0; j<10; j++) grid[i][j] = s[j];
		}
		cin >> op;
		for (int i=0; i<MAXM; i++) for (int j=0; j<MAXM; j++) if (grid[i][j] == 'F') dist[i][j] = 0;
		for (int i=0; i<MAXN; i++) {
			for (int j=0; j<10; j++) {
				for (int k=0; k<10; k++) {
					if (grid[j][k] == 'T') {
						int &res = dist[j][k];
						res = min(res, dist[j][k - 1] + 1);
						res = min(res, dist[j][k + 1] + 1);
						res = min(res, dist[j - 1][k] + 1);
						res = min(res, dist[j + 1][k] + 1);
					}
				}
			}
		}
		for (int i=0; i<10; i++) for (int j=0; j<10; j++) if (grid[i][j] == 'T') ans = max(ans, dist[i][j]);
		cout << (ans == INF ? -1 : ans) << "\n";
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