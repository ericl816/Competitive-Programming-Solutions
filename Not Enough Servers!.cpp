#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1048576;
int N, M, num, arr[55];
char ch[55];
bitset<55> DP[MAXN];

int main () {
  scanf("%d %d", &N, &M);
  for (int i=0; i<N; i++) {
    num = M;
    scanf("%s", &ch);
    for (int j=0; j<M; j++) {
      if (ch[j] == 'X') {
        arr[j] |= 1 << i;
        num--;
      }
    }
    if (num == M) {
      for (int j=0; j<M; j++) 
        arr[j] |= 1 << i;
    }
  }
  for (int i=0; i<1 << N; i++) {
    for (int j=0; j<M; j++) {
      int idx = arr[j] | i;
      if (arr[j] && (!i || DP[i].count()) && (DP[i].count() + 1 < DP[idx].count() || !DP[idx].count())) {
        DP[idx] = DP[i];
        DP[idx][j] = 1;
      }
    }
  }
  int idx = (1 << N) - 1;
  printf("%d\n", DP[idx].count());
  for (int i=0; i<M; i++) {
    if (DP[idx][i]) printf("%d ", i + 1);
  }
}
