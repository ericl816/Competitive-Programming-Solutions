#include <bits/stdc++.h>
#define ll long long
#define MAXM 20
#define MAXN 1000010
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define mii map<int, int>
#define umii unordered_map<int, int>
using namespace std;

int n, t, coins[MAXM], DP[MAXN][MAXM];

inline int Recur (int idx, int val) {
	if (val == 0) return 1;
	if ((idx >= n && val > 0) || val < 0) return 0;
	int &res = DP[val][idx];
	if (~res) return res;
	return res = Recur(idx + 1, val) + Recur(idx + 1, val - coins[idx]);
}

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> t;
	for (int i=0; i<n; i++) cin >> coins[i];
	memset(DP, -1, sizeof(DP));
	cout << Recur(0, t) << endl;
	return 0;
}