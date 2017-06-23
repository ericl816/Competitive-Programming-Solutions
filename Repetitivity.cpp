#include <bits/stdc++.h>
using namespace std;
int M, n, dp [10001][10001];
string s;
char ch[10001];
int main () {
  gets(ch);
  scanf("%d", &M);
   n = strlen(ch);
  for (int i=0; i<=n; i++) 
    dp[0][i] = dp[i][0] = 1;
  for (int i=0; i<n; i++) {
    for (int j=0; j<n; j++) {
      dp[i + 1][j + 1] = (dp[i][j + 1] + dp[i + 1][j]) % M;
      if (ch[i] ^ ch[j]) dp[i + 1][j + 1] = (M + dp[i + 1][j + 1] - dp[i][j]) % M;
    }
  }
  printf("%d\n", dp[n][n]);
}
