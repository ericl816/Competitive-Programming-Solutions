#include <bits/stdc++.h>
#define ll long long
#define MAXN 2010
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define mii map<int, int>
#define umii unordered_map<int, int>
using namespace std;

int N;
ll ans;
int DP[MAXN][MAXN];
string s[MAXN];

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i=1; i<=N; i++) {
		cin >> s[i];
		for (int j=0; j<N; j++) DP[j + 1][i] = s[i][j] == '#';
	}
	for (int i=N; i; i--) {
		for (int j=1; j<=N; j++) {
			if (DP[j][i] == 1) {
				DP[j][i] += min(DP[j - 1][i + 1], min(DP[j][i + 1], DP[j + 1][i + 1]));
				ans += DP[j][i];
			}
		}
	}
	cout << ans << endl;
	return 0;
}