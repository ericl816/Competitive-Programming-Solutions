#include <bits/stdc++.h>
#define ll long long
#define MAXN 5010
#define min(a, b) (a) < (b) ? (a) : (b)
#define max(a, b) (a) < (b) ? (b) : (a)
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
using namespace std;

int N, H;
ll g[MAXN], h[MAXN], q[MAXN], t[MAXN], flag, flag1, ans, DP[2][MAXN];
bool vis[MAXN];

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> H;
	for (int i=0; i<N; i++) cin >> g[i] >> h[i] >> q[i] >> t[i];
	for (int i=0; i<N; i++) {
		flag1 = flag ^ 1;
		for (int j=0; j<=H; j++) {
			if (j >= h[i]) {
				if (DP[flag][j] <= DP[flag1][j - h[i]] + g[i]) {
					DP[flag][j] = DP[flag1][j - h[i]] + g[i];
					vis[j] = 1;
				}
			}
			if (j >= t[i]) {
				if (DP[flag][j] <= DP[flag][j - t[i]] + q[i] && vis[j - t[i]]) {
					DP[flag][j] = DP[flag][j - t[i]] + q[i];
					vis[j] = 1;
				}
			}
		}
		for (int j=0; j<=H; j++) {
			DP[flag][j] = max(DP[flag][j], DP[flag1][j]);
			ans = max(ans, DP[flag][j]);
		}
		flag = flag1;
		memset(vis, 0, sizeof(vis));
		memset(DP[flag], 0, sizeof(DP[flag]));
	}
	cout << ans << "\n";
	return 0;
}