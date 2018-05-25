#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXN 40
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

struct Grid {
	int px, py, bx, by, num;
};

int R, C, px, py, bx, by, lx, ly;
char op[MAXN][MAXN];
int *movex = new int [4] {0, 0, -1, 1};
int *movey = new int [4] {-1, 1, 0, 0};
vector<Grid> vec[MAXN];
bool vis[MAXN][MAXN][MAXN][MAXN];
queue<Grid> q;
bool flag;

int main () {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> R >> C;
	for (int i=0; i<R; i++) {
		cin >> op[i];
		for (int j=0; j<C; j++) {
			if (op[i][j] == 'P') px = i, py = j;
			else if (op[i][j] == 'B') bx = i, by = j;
			else if (op[i][j] == 'X') lx = i, ly = j;
		}
	}
	vis[px][py][bx][by] = 1;
	q.push((Grid) {px, py, bx, by, 0});
	while (!q.empty()) {
		Grid curr = q.front();
		q.pop();
		if (curr.bx == lx && curr.by == ly) {
			cout << curr.num << "\n";
			flag = 1;
			return 0;
		}
		for (int i=0; i<4; i++) {
			int currpx = curr.px;
		    int currpy = curr.py;
		    int currbx = curr.bx;
		    int currby = curr.by;
		    int num = curr.num;
			int pxcoor = currpx + movex[i];
			int pycoor = currpy + movey[i];
			if (pxcoor >= 0 && pxcoor < R && pycoor >= 0 && pycoor < C && op[pxcoor][pycoor] != '#') {
				if (pxcoor == currbx && pycoor == currby) {
					if (currbx + movex[i] >= 0 && currbx + movex[i] < R && currby + movey[i] >= 0 && currby + movey[i] < C && op[currbx][currby] != '#') {
						currbx += movex[i];
						currby += movey[i];
					}
				}
				if (!vis[pxcoor][pycoor][currbx][currby]) {
					q.push((Grid) {pxcoor, pycoor, currbx, currby, num + 1});
					vis[pxcoor][pycoor][currbx][currby] = 1;
				}
			}
		}
	}
	if (!flag) cout << -1 << "\n";
	return 0;
}