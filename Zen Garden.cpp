#include<iostream>
using namespace std;

int N, M, a, d, val, arr [100001];
int main () {
  scanf("%d", &N);
  for (int i=0; i<N; i++) {
    scanf("%d", &arr[i]);
    val += arr[i];
  }
  scanf("%d", &M);
  for (int i=0; i<M; i++) {
    scanf("%d %d", &a, &d);
    val -= min(min(arr[a], arr[a - 1]), d);
  }
  printf("%d\n", val);
}
