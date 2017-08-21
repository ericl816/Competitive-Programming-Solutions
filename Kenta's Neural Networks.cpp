#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define MAXN 110
using namespace std;

string s1, s2;
int n, t, sum, DP[MAXN][MAXN];
double ans = INF;

inline void EditDist (string s1, string s2) {
  memset(DP, 0x3f, sizeof(DP));
  for (int a=0; a<=s1.length(); a++) DP[a][0] = a;
	for (int b=0; b<=s2.length(); b++) DP[0][b] = b;
	for (int i=1; i<=s1.length(); i++) {
		for (int j=1; j<=s2.length(); j++) {
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
	cin >> s1 >> n;
	for (int i=0; i<n; i++) {
		cin >> t;
		sum = 0;
		for (int j=0; j<t; j++) {
			cin >> s2;
			EditDist(s1, s2);
			sum += DP[s1.length()][s2.length()];
		}
		ans = min(ans, (double) sum / t);
	}
	printf("%.6lf\n", ans);
}
