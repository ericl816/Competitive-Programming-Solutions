#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2010, MOD = 1000000007;
int T, x, y, stress[MAXN][MAXN];

void solve () {
  for (int i=0; i<=2009; i++) {
    for (int j=0; j<=2009; j++) {
      if (j < i) {
        if (!j) stress[i][j] = 1;
        else if (i == j + 1) stress[i][j] = stress[i][j - 1] % MOD;
        else stress[i][j] = (stress[i - 1][j] % MOD + stress[i][j - 1] % MOD) % MOD;
      }
    }
  }
}

int main () {
  scanf("%d", &T);
  solve();
  for (int i=1; i<=T; i++) {
    scanf("%d-%d", &x, &y);
    printf("Case #%d: %d %d\n", i, stress[x][y], stress[y + 1][y]);
  }
  return 0;
}
