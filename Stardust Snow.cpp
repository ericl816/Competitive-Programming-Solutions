#include<bits/stdc++.h>
using namespace std;
const int MAXN = 52;
int R, C, S, B, K, M, T, V, c, r, val[MAXN][MAXN], temp[MAXN][MAXN], DP[MAXN][MAXN][MAXN][MAXN];

int solve(int time, int height, int degree, int snow) {
  int &ret = DP[time][height][degree][snow];
  if (~ret) return ret;
  if (degree == 0 || time == R + 1 || snow == 0) return 0;
    ret = 0;
    for (int i=-M; i<=M; i++) {
      if (height + i >= 1 && height + i <= C) {
          ret = max(ret, solve(time + 1, height + i, degree, snow));
        if (~val[time + 1][height + i] && temp[time + 1][height + i] < degree) 
          ret = max(ret, val[time + 1][height + i] + solve(time + 1, height + i, degree - temp[time + 1][height + i], snow - 1));
      }
    }
    return ret;
}

int main() {
    scanf("%d %d %d %d %d %d", &R, &C, &S, &B, &K, &M);
    memset(val, -1, sizeof val);
    for (int i=1; i<=S; i++) {
        scanf("%d %d %d %d", &T, &V, &c, &r);
        val[r][c] = V;
        temp[r][c] = T;
    }
    memset(DP, -1, sizeof DP);
    printf("%d\n", solve(0, 1, B, K));
}
