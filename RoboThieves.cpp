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

int N, M, sx, sy, ex, ey;
int dist[MAXN][MAXN];
string s;
char ch[MAXN][MAXN];
bool vis[MAXN][MAXN], flag[MAXN][MAXN];
priority_queue<pii> q;

inline bool Check (int x, int y) {
	return x >= 0 && x < N && y >= 0 && y < N;
}

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int *movex = new int [4] {0, 0, 1, -1};
	int *movey = new int [4] {1, -1, 0, 0};
	char *conveyor = new char [4] {'R', 'L', 'D', 'U'};
	cin >> N >> M;
	for (int i=0; i<N; i++) {
		cin >> s;
		for (int j=0; j<M; j++) {
			ch[i][j] = s[j];
			if (ch[i][j] == 'S') {
				sx = i;
				sy = j;
			}
		}
	}
	for (int i=0; i<N; i++) {
		for (int j=0; j<M; j++) {
			if (ch[i][j] == 'C') {
				for (int k=i; k>=0 && ch[k][j] != 'W'; k--) if (ch[k][j] == '.' || ch[k][j] == 'C' || ch[k][j] == 'S') flag[k][j] = 1;
				for (int k=i; k<N && ch[k][j] != 'W'; k++) if (ch[k][j] == '.' || ch[k][j] == 'C' || ch[k][j] == 'S') flag[k][j] = 1;
				for (int k=j; k>=0 && ch[i][k] != 'W'; k--) if (ch[i][k] == '.' || ch[i][k] == 'C' || ch[i][k] == 'S') flag[i][k] = 1;
				for (int k=j; k<M && ch[i][k] != 'W'; k++) if (ch[i][k] == '.' || ch[i][k] == 'C' || ch[i][k] == 'S') flag[i][k] = 1;
			}
		}
	}
	if (!flag[sx][sy]) q.push(mp(sx, sy));
	memset(dist, INF, sizeof(dist));
	dist[sx][sy] = 0;
	vis[sx][sy] = 1;
	while (!q.empty()) {
		pii curr = q.top();
		q.pop();
		vis[curr.f][curr.s] = 0;
		for (int i=0; i<4; i++) {
			int currx = curr.f + movex[i];
			int curry = curr.s + movey[i];
			if (!Check(currx, curry) || ch[currx][curry] == 'W' || flag[currx][curry]) continue;
			if (ch[curr.f][curr.s] == '.' || ch[curr.f][curr.s] == 'S' || ch[curr.f][curr.s] == conveyor[i]) {
				int nextcost = dist[curr.f][curr.s] + (ch[curr.f][curr.s] == conveyor[i] ? 0 : 1);
				if (nextcost < dist[currx][curry]) {
					dist[currx][curry] = nextcost;
					if (!vis[currx][curry]) {
						vis[currx][curry] = 1;
						q.push(mp(currx, curry));
					}
				}
			}
		}
	}
	for (int i=0; i<N; i++) for (int j=0; j<M; j++) if (ch[i][j] == '.') cout << (dist[i][j] == INF ? -1 : dist[i][j]) << "\n";
	return 0;
}