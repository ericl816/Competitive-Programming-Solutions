#include <bits/stdc++.h>
#define ll long long
#define MAXN 55
#define INF 0x3f3f3f3f
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

int n, m;
char grid[MAXN][MAXN];
string s;

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i=0; i<n; i++) {
		cin >> s;
		for (int j=0; j<m; j++) {
			grid[i][j] = s[j];
		}
	}
	for (int t=0; t<100; t++) {
		for (int i=0; i<n - 1; i++) {
			for (int j=0; j<m; j++) {
				if (grid[i][j] == 'o' && grid[i + 1][j] == '.') {
					swap(grid[i + 1][j], grid[i][j]);
				}
			}
		}
	}
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			cout << grid[i][j];
		}
		cout << endl;
	}
	return 0;	
}