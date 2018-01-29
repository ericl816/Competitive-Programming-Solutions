#include <bits/stdc++.h>
#define MAXN 2010
#define INF 0x3f3f3f3f
#define ll long long
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define mii map<int, int>
#define umii unordered_map<int, int>
using namespace std;

int xh, yh, T, x, y, l;
bool flag1, flag2;
int DP[MAXN][MAXN], xgrid[MAXN][MAXN], ygrid[MAXN][MAXN];

inline int Solve (int x, int y) {
	if (x == 0 && y == 0) return 0;
	int &res = DP[x][y];
	if (~res) return res;
	int ans = MAXN;
	if (x >= 1) ans = min(ans, Solve(x - 1, y) + xgrid[x - 1][y]);
	if (y >= 1) ans = min(ans, Solve(x, y - 1) + ygrid[x][y - 1]);
	return res = ans;
}

int main () {
	scanf("%d %d %d", &xh, &yh, &T);
	if (xh < 0) {
		xh = abs(xh);
		flag1 = 1;
	}
	if (yh < 0) {
		yh = abs(yh);
		flag2 = 1;
	}
	for (int i=0; i<T; i++) {
		scanf("%d %d %d", &x, &y, &l);
		if (flag1) x *= -1;
		if (flag2) y *= -1;
		if (x + l >= 0 && x + l <= xh) for (int j=max(0, y - l); j<=min(yh, y + l); j++) xgrid[x + l][j]++;
		if (y + l >= 0 && y + l <= yh) for (int j=max(0, x - l); j<=min(xh, x + l); j++) ygrid[j][y + l]++; 
	}
	memset(DP, -1, sizeof(DP));
	printf("%d\n", Solve(xh, yh));
	return 0;
}