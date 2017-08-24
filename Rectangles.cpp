#include <bits/stdc++.h>
#define ll long long
#define MAXN 110
using namespace std;

int n, m, grid[MAXN][MAXN];
ll row[MAXN], col[MAXN], area, ans;

int main() {
	scanf("%d%d", &n, &m);
	area = n * m;
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			scanf("%d", &grid[i][j]);
			row[i] += grid[i][j];
			col[j] += grid[i][j];
		}
	}
	for (int i=0; i<n; i++) {
		ans += (1LL << row[i]) - 1;
		ans += (1LL << (m - row[i])) - 1;
	}
	for (int i=0; i<m; i++) {
		ans += (1LL << col[i]) - 1;
		ans += (1LL << (n - col[i])) - 1;
	}
	ans -= area;
	printf("%lld\n", ans);
	return 0;
}
