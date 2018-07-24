#include <iostream>
#include <cstring>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define max(a,b) ((a) < (b) ? (b) : (a))
char _;
using namespace std;

int n, t;
int ans = 0;
int p[2001][3], v[2001][3];
int dp[10001];

int main () {
  scan(n); scan(t);
  for (int i=0; i<n; i++) {
    for (int j=0; j<3; j++) {
      scan(p[i][j]); scan(v[i][j]);
    }
  }
  memset(dp, -1, sizeof dp);
  dp[0] = 0;
  for (int i=0; i<n; i++) {
    for (int j=t; j>=0; j--) {
      for (int k=0; k<3; k++) {
        if (t >= j + p[i][k] && 0 <= dp[j])
        dp[j + p[i][k]] = max(dp[j] + v[i][k], dp[j + p[i][k]]);
      }
    }
  }
  for (int i=0; i<=t; i++) ans = max(ans, dp[i]);
  printf("%d\n", ans);
}