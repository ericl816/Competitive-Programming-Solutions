#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXN 15
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

int T = 5, srcx, srcy, destx, desty;
int *movex = new int[8] {0, 0, -1, 1, -1, 1, -1, 1}, *movey = new int[8] {-1, 1, 0, 0, -1, -1, 1, 1};
char grid[MAXN][MAXN];
int dist[MAXN][MAXN];
bool vis[MAXN][MAXN];
string s;

int main () {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	while (T--) {
		queue<pii> q;
		srcx = srcy = destx = desty = 0;
		memset(dist, 0, sizeof(dist));
		memset(vis, 0, sizeof(vis));
		for (int i=0; i<8; i++) {
			cin >> s;
			for (int j=0; j<8; j++) {
				grid[i][j] = s[j];
				if (grid[i][j] == 'A') srcx = i, srcy = j;
				if (grid[i][j] == 'B') destx = i, desty = j;
			}
		}
		vis[srcx][srcy] = 1;
		q.push(mp(srcx, srcy));
		while (!q.empty()) {
			pii curr = q.front();
			q.pop();
			int currx = curr.f, curry = curr.s;
			if (currx == destx && curry == desty) {
				cout << dist[currx][curry] << "\n";
				break;
			}
			for (int i=0; i<8; i++) {
				int x = currx + movex[i], y = curry + movey[i];
				if (x < 0 || x >= 8 || y < 0 || y >= 8 || grid[x][y] == '#' || vis[x][y]) continue;
				dist[x][y] = dist[currx][curry] + 1;
				vis[x][y] = 1;
				q.push(mp(x, y));
			}
		}
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