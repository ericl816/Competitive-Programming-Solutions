#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define ull unsigned long long
#define MAXN 3010
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
#define DEBUG 1
#ifdef DEBUG
	#define D(x...) printf(x)
#else
	#define D(x...)
#endif
using namespace std;

int m, n, sx, sy;
int movex[4] = {0, 0, -1, 1}, movey[4] = {-1, 1, 0, 0};
char grid[MAXN][MAXN];
string s;
bool vis[MAXN][MAXN];
bool ok[MAXN];
queue<pii> q;

int main (int argc, char const *argv[]) {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> m >> n;
	for (int i=0; i<n; i++) {
		cin >> s;
		for (int j=0; j<m; j++) {
			grid[i][j] = s[j];
			if (s[j] == '1') {
				sx = i;
				sy = j;
			}
		}
	}
	q.push(mp(sx, sy));
	vis[sx][sy] = 1;
	while (!q.empty()) {
		pii curr = q.front();
		q.pop();
		if (grid[curr.f][curr.s] != '#' && grid[curr.f][curr.s] != '0') ok[grid[curr.f][curr.s] - '0'] = 1;
		for (int i=0; i<4; i++) {
			int x = curr.f + movex[i], y = curr.s + movey[i];
			if (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] != '#' && !vis[x][y]) {
				vis[x][y] = 1;
				q.push(mp(x, y));
			}
		}
	}
	for (int i=1; i<=9; i++) if (ok[i]) cout << i << " ";
	cout << "\n";
	return 0;
}

/* 
 * Look for:
 * the exact constraints (multiple sets are too slow for n=10^6 :( ) 
 * special cases (n=1?)
 * overflow (ll vs int?)
 * array bounds
 */