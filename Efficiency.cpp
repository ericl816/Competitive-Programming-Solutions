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

int R, C, sx, sy, ans1, ans2, ans3, ans4, ans;
string s;
char grid[MAXN][MAXN];

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> R >> C;
	for (int i=0; i<R; i++) {
		cin >> s;
		for (int j=0; j<C; j++) {
			grid[i][j] = s[j];
			if (grid[i][j] == 'H') {
				sx = i;
				sy = j;
			}
		}
	}
	for (int i=0; i<sx; i++) {
		if (grid[i][sy] == 'C') ans1++;
	}
	for (int i=sy; i<C; i++) {
		if (grid[sx][i] == 'C') ans2++;
	}
	for (int i=0; i<sy; i++) {
		if (grid[sx][i] == 'C') ans3++;
	}
	for (int i=sx; i<R; i++) {
		if (grid[i][sy] == 'C') ans4++;
	}
	ans = max(ans1, max(ans2, max(ans3, ans4)));
	cout << ans << "\n";
	return 0;
}