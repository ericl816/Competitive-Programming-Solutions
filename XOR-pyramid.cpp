#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXN 5010
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

int n, q, l, r;
int a[MAXN];
int DP[MAXN][MAXN];

int main () {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i];
		DP[0][i] = a[i];
	}
	for (int i=1; i<n; i++) for (int j=0; j<=n - i; j++) DP[i][j] = DP[i - 1][j] ^ DP[i - 1][j + 1];
	for (int i=1; i<n; i++) for (int j=0; j<n - i; j++) DP[i][j] = max(DP[i][j], max(DP[i - 1][j], DP[i - 1][j + 1]));
	cin >> q;
	while (q--) {
		cin >> l >> r;
		--l;
		cout << DP[r - l - 1][l] << "\n";
	}
	return 0;
}