#include<bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define max(a,b) ((a) < (b) ? (b) : (a))
char _;
using namespace std;
const int MAXN = 55;
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
    scan(R); scan(C); scan(S); scan(B); scan(K); scan(M);
    memset(val, -1, sizeof val);
    memset(temp, -1, sizeof temp);
    memset(DP, -1, sizeof DP);
    for (int i=1; i<=S; i++) {
        scan(T); scan(V); scan(c); scan(r);
        val[r][c] = V;
        temp[r][c] = T;
    }
    printf("%d\n", solve(0, 1, B, K));
}