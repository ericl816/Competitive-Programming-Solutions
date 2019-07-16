#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;

int N, K, sum1, sum2, arr1[MAXN], arr2[MAXN];

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
