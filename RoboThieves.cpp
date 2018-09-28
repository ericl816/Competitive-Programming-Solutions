#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define ull unsigned long long
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
#ifdef DEBUG
	#define D(x...) printf(x)
#else
	#define D(x...)
#endif
using namespace std;

int N, M, sx, sy;
string s;
char grid[MAXN][MAXN];
char conveyors[4] = {'L', 'R', 'U', 'D'};
int movex[4] = {0, 0, -1, 1}, movey[4] = {-1, 1, 0, 0};
bool flag[MAXN][MAXN], vis[MAXN][MAXN];
priority_queue<pii> pq;
int dist[MAXN][MAXN];

int main (int argc, char const *argv[]) {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for (int i=0; i<N; i++) {
		cin >> s;
		for (int j=0; j<M; j++) {
			grid[i][j] = s[j];
			if (grid[i][j] == 'S') {
				sx = i, sy = j;
			}
		}
	}
	for (int i=0; i<N; i++) {
		for (int j=0; j<M; j++) {
			if (grid[i][j] == 'C') {
				for (int k=j; k<M && grid[i][k] != 'W'; k++) {
					if (grid[i][k] == 'S' || grid[i][k] == '.' || grid[i][k] == 'C') flag[i][k] = 1;
				}
				for (int k=j; k>=0 && grid[i][k] != 'W'; k--) {
					if (grid[i][k] == 'S' || grid[i][k] == '.' || grid[i][k] == 'C') flag[i][k] = 1;
				}
				for (int k=i; k<N && grid[k][j] != 'W'; k++) {
					if (grid[k][j] == 'S' || grid[k][j] == '.' || grid[k][j] == 'C') flag[k][j] = 1;
				}
				for (int k=i; k>=0 && grid[k][j] != 'W'; k--) {
					if (grid[k][j] == 'S' || grid[k][j] == '.' || grid[k][j] == 'C') flag[k][j] = 1;
				}
			}
		}
	}
	memset(dist, INF, sizeof(dist));
	if (!flag[sx][sy]) pq.push(mp(sx, sy));
	vis[sx][sy] = 1;
	dist[sx][sy] = 0;
	while (!pq.empty()) {
		pii curr = pq.top();
		pq.pop();
		vis[curr.f][curr.s] = 0;
		for (int i=0; i<4; i++) {
			int nextx = curr.f + movex[i], nexty = curr.s + movey[i];
			// if (flag[nextx][nexty] || grid[nextx][nexty] == 'W' || nextx < 0 || nextx >= N || nexty < 0 || nexty >= M) continue;
			if (grid[curr.f][curr.s] == '.' || grid[curr.f][curr.s] == 'S' || grid[curr.f][curr.s] == conveyors[i]) {
				if (flag[nextx][nexty] || grid[nextx][nexty] == 'W' || nextx < 0 || nextx >= N || nexty < 0 || nexty >= M) continue;
				int nextcost = dist[curr.f][curr.s] + (grid[curr.f][curr.s] == conveyors[i] ? 0 : 1);
				if (dist[nextx][nexty] > nextcost) {
					dist[nextx][nexty] = nextcost;
					if (!vis[nextx][nexty]) {
						vis[nextx][nexty] = 1;
						pq.push(mp(nextx, nexty));
					}
				}
			}
		}
	}
	for (int i=0; i<N; i++) {
		for (int j=0; j<M; j++) {
			if (grid[i][j] == '.') {
				cout << (dist[i][j] == INF ? -1 : dist[i][j]) << "\n";
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