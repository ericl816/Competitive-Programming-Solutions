#include <bits/stdc++.h>
#define ll long long
#define MAXN 1510
#define INF 0x3f3f3f3f
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define mii map<int, int>
#define umii unordered_map<int, int>
using namespace std;

int R, C, sx, sy, ex, ey;
string s;
int dist[MAXN][MAXN];
vector<pii> adj[MAXN][MAXN];
queue<pii> q;
char grid[MAXN][MAXN];
bool vis[MAXN][MAXN];

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> R >> C;
	for (int i=0; i<R; i++) {
		cin >> s;
		for (int j=0; j<C; j++) {
		  grid[i][j] = s[j];
		  if (grid[i][j] == 'S') sx = i, sy = j;
		  else if (grid[i][j] == 'D') ex = i, ey = j;
		}
	}
	// Preprocess the cells by storing them into the 2D adjacency list
	for (int i=0; i<R; i++) {
		for (int j=0, num=0; j<C; j++) {
			if (grid[i][j] == '*') num++;
			// Go to the left in column
			if (j - 1 >= 0 && grid[i][j - 1] != '*' && num < 2) adj[i][j].pb(mp(i, j - 1));
		}
		for (int j=C - 1, num=0; j>=0; j--) {
			if (grid[i][j] == '*') num++;
			// Go to the right in column
			if (j + 1 < C && grid[i][j + 1] != '*' && num < 2) adj[i][j].pb(mp(i, j + 1));
		}
	}
	for (int i=0; i<C; i++) {
		for (int j=0, num=0; j<R; j++) {
			if (grid[j][i] == '*') num++;
			// Go to the left in row
			if (j - 1 >= 0 && grid[j - 1][i] != '*' && num < 2) adj[j][i].pb(mp(j - 1, i));
		}
		for (int j=R - 1, num=0; j>=0; j--) {
			if (grid[j][i] == '*') num++;
			// Go to the right in row
			if (j + 1 < R && grid[j + 1][i] != '*' && num < 2) adj[j][i].pb(mp(j + 1, i));
		}
	}
	vis[sx][sy] = 1;
	memset(dist, INF, sizeof(dist));
	dist[sx][sy] = 0;
	q.push(mp(sx, sy));
	while (!q.empty()) {
		pii curr = q.front();
		q.pop();
		vis[curr.f][curr.s] = 0;
		if (curr.f == ex && curr.s == ey) {
			cout << dist[curr.f][curr.s] << endl;
			return 0;
		}
		for (size_t i=0; i<adj[curr.f][curr.s].size(); i++) {
			pii &next = adj[curr.f][curr.s][i];
			int nextcost = dist[curr.f][curr.s] + 1;
			if (nextcost < dist[next.f][next.s]) {
				dist[next.f][next.s] = nextcost;
				if (!vis[next.f][next.s]) {
					vis[next.f][next.s] = 1;
					q.push(mp(next.f, next.s));
				}
			}
		}
	}
	cout << -1 << endl;
	return 0;
}