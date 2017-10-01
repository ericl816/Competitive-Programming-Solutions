#include <bits/stdc++.h>
#define ll long long
#define MAXN 100010
#define INF 0x3f3f3f3f
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define msll map<string, ll>
#define psll pair<string, ll>
using namespace std;

int N, T, m, pos, sx = 0;
string orient;
bool grid[MAXN];

int main () { 
  cin.sync_with_stdio(0);
  cin.tie(0);
	cin >> N >> T >> orient;
	for (int i=0; i<N; i++) {
		if (orient[i] == '|') {
			grid[i] = 1;
			sx += 3;
		}
		else if (orient[i] == '-') {
			grid[i] = 0;
			sx++;
		}
	}
	pos = sx;
	while (T--) {
		cin >> m;
		grid[m - 1] = !grid[m - 1]; //Flip direction of walls
		if (grid[m - 1]) sx = pos + 2;
		else sx = pos - 2;
		if (!grid[0]) cout << sx << "\n";
		else cout << 1 << "\n";
		pos = sx;
	}
	return 0;
}