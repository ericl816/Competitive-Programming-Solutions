#include <bits/stdc++.h>
#define ll long long
#define MAXN 41
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

int n, a, b, c, d;
int arr[5][4] = {{2, 1, 0, 2}, {1, 1, 1, 1}, {0, 0, 2, 1}, {0, 3, 0, 0}, {1, 0, 0, 1}};
bool DP[MAXN][MAXN][MAXN][MAXN];

bool Check (int a, int b, int c, int d) {
	return (a < 0 || b < 0 || c < 0 || d < 0) ? 0 : !DP[a][b][c][d];
}

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	for (int i=0; i<MAXN; i++) 
		for (int j=0; j<MAXN; j++)
			for (int k=0; k<MAXN; k++)
				for (int l=0; l<MAXN; l++)
					for (int m=0; m<5; m++)
						if (Check(i - arr[m][0], j - arr[m][1], k - arr[m][2], l - arr[m][3])) DP[i][j][k][l] = 1;
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a >> b >> c >> d;
		if (DP[a][b][c][d]) cout << "Patrick" << endl;
		else cout << "Roland" << endl;
	}
	return 0;
}