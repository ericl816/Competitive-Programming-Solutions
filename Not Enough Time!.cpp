#include <iostream>
#include <cstring>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define max(a,b) ((a) < (b) ? (b) : (a))
char _;
using namespace std;

int n, t, ans;
int P[2001][3], V[2001][3];
int DP[10001];

int main () {
  cin >> n >> t;
  for (int i=0; i<n; i++) {
    for (int j=0; j<3; j++) {
      cin >> P[i][j] >> V[i][j];
    }
  }
  memset(DP, -1, sizeof(DP));
  DP[0] = 0;
  for (int i=0; i<n; i++) {
    for (int j=t; j>=0; j--) {
      for (int k=0; k<3; k++) {
        if (t >= j + P[i][k] && DP[j] >= 0) DP[j + P[i][k]] = max(DP[j] + V[i][k], DP[j + P[i][k]]);
      }
    }
  }
  for (int i=0; i<=t; i++) ans = max(ans, DP[i]);
  cout << ans << "\n";
  return 0;
}
