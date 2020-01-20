#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXM 1010
#define MAXN 5010
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

int N, H, idx1, idx2;
ll g[MAXN], h[MAXN], q[MAXN], t[MAXN];
ll DP[2][MAXN];
ll ans;
bool vis[MAXN];

int main () {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> H;
	for (int i=0; i<N; i++) cin >> g[i] >> h[i] >> q[i] >> t[i];
	for (int i=0; i<N; i++) {
	    memset(vis, 0, sizeof(vis));
	    idx1 = i & 1;
	    idx2 = (i + 1) & 1;
	    memset(DP[idx1], 0, sizeof(DP[idx1]));
		for (int j=0; j<=H; j++) {
			if (j >= h[i]) {
				DP[idx1][j] = max(DP[idx1][j], DP[idx2][j - h[i]] + g[i]);
				vis[j] = 1;
			}
			if (j >= t[i] && vis[j - t[i]]) {
				DP[idx1][j] = max(DP[idx1][j], DP[idx1][j - t[i]] + q[i]);
				vis[j] = 1;
			}
		}
		for (int j=0; j<=H; j++) DP[idx1][j] = max(DP[idx1][j], DP[idx2][j]);
	}
	for (int i=0; i<=H; i++) ans = max(ans, DP[(N - 1) & 1][i]);
	cout << ans << "\n";
	return 0;
}