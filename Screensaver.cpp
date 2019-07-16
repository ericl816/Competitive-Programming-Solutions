#include <bits/stdc++.h>
#define ll long long
#define MAXN 110
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
using namespace std;

int N, M, T, sx, sy, ans = 1;
string s;
char grid[MAXN][MAXN];

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M >> T;
	for (int i=0; i<M; i++) {
		cin >> s;
		for (int j=0; j<N; j++) {
			grid[i][j] = s[j];
			if (grid[i][j] == 'O') {
				sx = i;
				sy = j;
			}
		}
	}
	const int *move = new int [2]{0, 1};
	for (; ans<=T; ans++) {
		sx += move[0];
		sy += move[1];
		if (!(sx >= 0 && sx < M && sy >= 0 && sy < N)) break;
		if (grid[sx][sy] == '.') continue;
		if (grid[sx][sy] == '-') {
			if (!move[0]) continue; //Going horizontally
			else {
				move = new int [2]{-move[0], 0};
				grid[sx][sy] = '|';
			}
		}
		else if (grid[sx][sy] == '|') {
			if (move[0] ^ 0) continue;
			else {
			  move = new int[2]{0, -move[1]};
				//*move = new int [2]{0, -move[1]};
				grid[sx][sy] = '-';
			}
		}
		else if (grid[sx][sy] == '/') {
			move = new int [2]{-move[1], -move[0]};
			grid[sx][sy] = '\\';
		}
		else if (grid[sx][sy] == '\\') {
			move = new int [2]{move[1], move[0]};
			grid[sx][sy] = '/';
		}
	}
	if (sx >= 0 && sx < M && sy >= 0 && sy < N) cout << "The observer stays within the grid." << "\n";
	else cout << "The observer leaves the grid after " << ans << " tick(s)." << "\n";
	return 0;
}
