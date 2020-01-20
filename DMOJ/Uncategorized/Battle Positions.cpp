#include<iostream>

using namespace std;

int I, N, J, X, Y, K, arr [100001], ans = 0;

void calc () {
  for (int i=0; i<I; i++) {
    arr[i] = arr[i] + arr[i - 1];
    if (arr[i] < N) ans++;
  }
}

int main () {
  scanf("%d", &I); scanf("%d", &N); scanf("%d", &J);
  for (int i=0; i<J; i++) {
    scanf("%d %d %d", &X, &Y, &K);
    arr[X - 1] += K;
    arr[Y] -= K;
  }
  calc();
  printf("%d\n", ans);
}