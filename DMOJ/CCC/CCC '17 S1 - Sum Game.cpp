#include<bits/stdc++.h>
using namespace std;

int N, K = 0, sum1 = 0, sum2 = 0, arr1[100010], arr2[100010];

int main () {
  scanf("%d", &N);
  for (int i=0; i<N; i++) scanf("%d", &arr1[i]);
  for (int i=0; i<N; i++) scanf("%d", &arr2[i]);
  for (int i=0; i<N; i++) {
    sum1 += arr1[i];
    sum2 += arr2[i];
    if (sum1 == sum2) K = i + 1;
  }
  printf("%d\n", K);
}