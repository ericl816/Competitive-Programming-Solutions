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

int T, a, len, width, num, xcoor, ycoor;
bool flag;
bool grid[MAXN][MAXN];

inline int Check_Surrounding (bool a[MAXN][MAXN], int r, int c) {
	int cnt = 0;
	for (int i=r - 1; i<= r + 1; i++) {
		for (int j=c - 1; j<=c + 1; j++) {
			if (!a[i][j]) cnt++;
		}
	}
	return cnt;
}

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> a;
		len = sqrt(a);
		width = len;
		while (len * width < a) width++;
		memset(grid, 0, sizeof(grid));
		num = 0;
		flag = 0;
		// For phase 1
		for (int i=2; i<=width - 1; i++) {
			for (int j=2; j<=len - 1; j++) {
				while (Check_Surrounding(grid, i, j) > 4) {
					cout << i << " " << j << "\n";
					cin >> xcoor >> ycoor;
					if (!grid[xcoor][ycoor]) {
						grid[xcoor][ycoor] = 1;
						num++;
					}
				}
			}
		}
		while (num < width * len) {
			for (int i=2; i<=width - 1; i++) {
				for (int j=2; j<=len - 1; j++) {
					if (Check_Surrounding(grid, i, j) > 0) {
						cout << i << " " << j << "\n";
						cin >> xcoor >> ycoor;
						if (xcoor == 0 && ycoor == 0) {
							flag = 1;
							break;
						}
						if (!grid[xcoor][ycoor]) {
							grid[xcoor][ycoor] = 1;
							num++;
						}
					}
				}
				if (flag) break;
			}
			if (flag) break;
		}
	}
	return 0;
}
