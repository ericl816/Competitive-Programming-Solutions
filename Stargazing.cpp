#include <bits/stdc++.h>
#define MAXN 2010
#define INF 0x3f3f3f3f
#define ll long long
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define mii map<int, int>
#define umii unordered_map<int, int>
using namespace std;

int N, P, X, Y, ans = 1;
pii planets[MAXN];
bool vis[MAXN][MAXN];

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	vis[1000][1000] = 1;
	planets[1] = mp(1000, 1000);
	for (int i=2; i<=N; i++) {
		cin >> P >> X >> Y;
		int xcoor = X + planets[P].f;
		int ycoor = Y + planets[P].s;
		if (!vis[xcoor][ycoor]) {
			vis[xcoor][ycoor] = 1;
			ans++;
		}
		planets[i] = mp(xcoor, ycoor);
	}
	cout << ans << endl;
	return 0;
}