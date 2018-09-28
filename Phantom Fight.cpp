#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define min(a, b) (a) < (b) ? (b) : (a)
#define max(a, b) (a) < (b) ? (b) : (a)
#define MAXN 10010
#define MAXM 5010
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define mii map<int, int>
#define umii unordered_map<int, int>
#define println cout << "\n";
using namespace std;

int N, M, res, ans;
int s[MAXN], m[MAXN];
int DP[MAXN][2]; // Stores the amount of magic

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	memset(DP, -1, sizeof(DP));
	for (int i=0; i<N; i++) cin >> s[i] >> m[i];
	DP[M][res] = 0;
	for (int i=0; i<N; i++) {
		for (int j=0; j<=10000; j++) {
			if (~DP[j][res]) {
				DP[j][res ^ 1] = max(DP[j][res], DP[j][res ^ 1]);
				if (j >= s[i]) {
					int val = j + m[i] - s[i];
					DP[val][res ^ 1] = max(DP[val][res ^ 1], DP[j][res] + 1);
				}
			}
		}
		res ^= 1;
	}
	for (int i=0; i<=10000; i++) ans = max(ans, DP[i][res]);
	for (int i=10000; i>=0; i--) {
		if (DP[i][N & 1] == ans) {
			cout << ans << " " << i << "\n";
			break;
		}
	}
	return 0;
}