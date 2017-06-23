#include<bits/stdc++.h>
using namespace std;

int N, M, x, y, w, h, area = 0;
short arr [10005][10005];

void compress (int a, int b, int c, int d) {
   arr[a + c + 1][b + d + 1]++;
   arr[a + 1][b + 1]++;
   arr[a + c + 1][b + 1]--;
   arr[a + 1][b + d + 1]--;
}

int main () {
  scanf("%d %d", &N, &M);
  for (int i=0; i<M; i++) {
    scanf("%d %d %d %d", &x, &y, &w, &h);
    compress(x, y, w, h);
  }
  for (int i=1; i<=N; i++) {
    for (int j=1; j<=N; j++) {
      arr[i][j] = arr[i][j] + arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1];
      area = area + (arr[i][j] & 1);
    }
  }
     printf("%d\n", area);
}
