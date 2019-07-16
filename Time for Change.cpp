#include <bits/stdc++.h>
#define ll long long
#define MAXN 110
#define INF 0x3f3f3f3f
#define min(a, b) (a) < (b) ? (a) : (b)
#define max(a, b) (a) < (b) ? (b) : (a)
using namespace std;

int m, n, c, DP[MAXN];

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	for (int i=0; i<5; i++) {
		cin >> m >> n;
		memset(DP, INF, sizeof(DP));
		DP[0] = 0;
		for (int j=0; j<n; j++) {
			cin >> c;
			for (int k=c; k<=m; k++) DP[k] = min(DP[k], DP[k - c] + 1);
		}
		cout << DP[m] << "\n";
	}
	return 0;
}