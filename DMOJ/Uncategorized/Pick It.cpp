#include <bits/stdc++.h>
#define ll long long
#define MAXN 210
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define mii map<int, int>
#define umii unordered_map<int, int>
using namespace std;

int n;
int arr[MAXN];
int DP[MAXN][MAXN];

inline int Recur (int l, int r) {
	if (l == r) return 0;
	int &res = DP[l][r];
	if (~res) return res;
	int ans = 0;
	for (int i=l + 1; i<r; i++) ans = max(ans, Recur(l, i) + Recur(i, r) + arr[l] + arr[r] + arr[i]);
	return res = ans;
}

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	while (1) {
	  cin >> n;
	  if (n == 0) break;
		for (int i=0; i<n; i++) cin >> arr[i];
		memset(DP, -1, sizeof(DP));
		cout << Recur(0, n - 1) << endl;
	}
	return 0;
}