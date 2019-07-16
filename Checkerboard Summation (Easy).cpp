#include<bits/stdc++.h>
#define ll long long
using namespace std;

int M, N, R, C, X, R1, C1, R2, C2, arr [3001][3001];
ll PSA [3001][3001], cnt;
bool odd;

void initialize () {
  while (R ^ 0) {
    arr[R][C] = X;
    scanf("%d %d %d", &R, &C, &X);
    X = ((R + C) % 2 == 1 ? -X : X);
  }
}

void computePSA () {
   PSA[0][0] = arr[0][0];
  for (int i=1; i<=M; i++)
    for (int j=1; j<=N; j++)
      PSA[i][j] = arr[i][j] - PSA[i - 1][j - 1] + PSA[i - 1][j] + PSA[i][j - 1];
}

int main () {
  scanf("%d %d", &M, &N);
  scanf("%d %d %d", &R, &C, &X);
  X = ((R + C) % 2 == 1 ? -X : X);
  initialize();
  computePSA(); 
  scanf("%d %d %d %d", &R1, &C1, &R2, &C2);
  while (R1 ^ 0) {
    cnt = ((R1 + C1) % 2 == 1 ? -(PSA[R1 - 1][C1 - 1] - PSA[R1 - 1][C2] - PSA[R2][C1 - 1] + PSA[R2][C2]) : PSA[R1 - 1][C1 - 1] - PSA[R1 - 1][C2] - PSA[R2][C1 - 1] + PSA[R2][C2]);
    printf("%lld\n", cnt);
    scanf("%d %d %d %d", &R1, &C1, &R2, &C2);
  }
}
