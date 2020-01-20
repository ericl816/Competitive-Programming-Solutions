#include <bits/stdc++.h>
using namespace std;

int N, M, bit;
int main () {
  scanf("%d %d", &N, &M);
  for (int i=0; i<N; i++) {
    bit = (i ^ (i >> 1)) << 10;
    for (int i=0; i<M; i++) printf("%d ", bit | (i ^ (i >> 1)));
    printf("\n");
  }
}