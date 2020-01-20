#include <bits/stdc++.h>
#define ll long long
#define MAXN 31
#define INF 0x3f3f3f3f
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define mii map<int, int>
#define umii unordered_map<int, int>
using namespace std;
int R, C, K, rol, col;
bool has[MAXN][MAXN];
int DP[MAXN][MAXN];
int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> R >> C >> K;
	for (int i=0; i<K; i++) {
		cin >> rol >> col;
		DP[rol][col] = 0;
		has[rol][col] = 1;
	}
	DP[1][1] = has[1][1] = 1;
	for (int i=1; i<=R; i++) for (int j=1; j<=C; j++) if (!has[i][j]) DP[i][j] = DP[i - 1][j] + DP[i][j - 1];
	cout << DP[R][C] << "\n";
	return 0;
}