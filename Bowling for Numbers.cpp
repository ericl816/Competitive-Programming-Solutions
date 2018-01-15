#include <bits/stdc++.h>
#define ll long long
#define MAXM 510
#define MAXN 30010
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

int t, n, k, w, res;
int psa[MAXN], val[MAXN];
int DP[2][MAXN];

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	for (int i=0; i<t; i++) {
		cin >> n >> k >> w;
		memset(psa, 0, sizeof(psa));
		memset(val, 0, sizeof(val));
		memset(DP, 0, sizeof(DP));
		for (int j=1; j<=n; j++) {
		  cin >> psa[j];
		  psa[j] += psa[j - 1];
		}
		for (int j=1; j<=n; j++) val[j] = psa[j] - psa[max(0, j - w)];
		for (int j=1; j<=k; j++) {
			for (int res=1; res<=n; res++) DP[j & 1][res] = max(DP[j & 1][res - 1], DP[(j & 1) ^ 1][max(0, res - w)] + val[res]);
		}
		cout << DP[k & 1][n] << endl;
	}
	return 0;
}