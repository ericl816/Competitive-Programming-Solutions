#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define MAXN 110
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

string s1, s2;
int n, t, sum;
int DP[MAXN][MAXN];
double ans = INF;

inline void EditDist () {
	for (int i=0; i<=s1.size(); i++) DP[i][0] = i;
	for (int i=0; i<=s2.size(); i++) DP[0][i] = i;
	for (int i=1; i<=s1.size(); i++) {
		for (int j=1; j<=s2.size(); j++) {
		  DP[i][j] = MAXN;
		  if (s1[i - 1] ^ s2[j - 1]) {
		      DP[i][j] = min(DP[i][j], DP[i - 1][j] + 1);
		      DP[i][j] = min(DP[i][j], DP[i][j - 1] + 1);
		      DP[i][j] = min(DP[i][j], DP[i - 1][j - 1] + 1);
		  }
		  else DP[i][j] = DP[i - 1][j - 1];
		}
	}
}

int main () {
	cin.sync_with_stdio(0);
	cin >> s1 >> n;
	for (int i=0; i<n; i++) {
		cin >> t;
		sum = 0;
		for (int j=0; j<t; j++) {
			cin >> s2;
			EditDist();
			sum += DP[s1.size()][s2.size()];
		}
		ans = min(ans, static_cast<double>(1.0 * sum / t));
	}
	cout << setprecision(6) << fixed << ans << "\n";
	return 0;
}