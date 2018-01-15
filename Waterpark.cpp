#include <bits/stdc++.h>
#define ll long long
#define MAXN 10010
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

int n, x, y;
int DP[MAXN];
vi adj[MAXN];

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	while (1) {
	  cin >> x >> y;
	  if (!x) break;
	  adj[x].pb(y);
	}
	DP[1] = 1;
	for (int i=1; i<=n; i++) {
		for (size_t j=0; j<adj[i].size(); j++) {
			int &next = adj[i][j];
			DP[next] += DP[i];
		}
	}
	cout << DP[n] << endl;
	return 0;
}