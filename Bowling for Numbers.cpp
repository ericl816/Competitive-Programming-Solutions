#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXN 30010
#define INF 0x3f3f3f3f
#define min(a, b) (a) < (b) ? (a) : (b)
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

int t, n, k, w, res;
int PSA[MAXN], val[MAXN];
int DP[2][MAXN];

int main () {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	for (int i=0; i<t; i++) {
		cin >> n >> k >> w;
		memset(PSA, 0, sizeof(PSA));
		memset(DP, 0, sizeof(DP));
		memset(val, 0, sizeof(val));
		for (int j=1; j<=n; j++) {
			cin >> PSA[j];
			PSA[j] += PSA[j - 1];
		}
		for (int j=1; j<=n; j++) val[j] = PSA[j] - PSA[max(0, j - w)];
		for (int j=1; j<=k; j++) for (int l=1; l<=n; l++) DP[j & 1][l] = max(DP[j & 1][l - 1], DP[(j + 1) & 1][max(0, l - w)] + val[l]);
		cout << DP[k & 1][n] << "\n";
	}
	return 0;
}