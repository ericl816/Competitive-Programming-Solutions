#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXN 310
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

// Same as CCO '14 P1 - Troyangles

int N, T = 5;
ll ans;
int DP[MAXN][MAXN];
string s[MAXN];

int main () {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	while (T--) {
		memset(DP, 0, sizeof(DP));
		ans = 0;
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
	}
	return 0;
}