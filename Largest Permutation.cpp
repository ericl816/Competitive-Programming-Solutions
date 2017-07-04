#include<bits/stdc++.h>
using namespace std;

int N, K, arr[100010], idxarr[100010], cnt = 0, idx, idx1, idx2; 

void swap () {
  for (int i=1; i<=N && K > cnt; i++) {
    idx = N - i + 1;
    if (arr[i] ^ idx) {
      cnt++;
      idx1 = idxarr[idx];
      idx2 = idx1;
      idxarr[idx] = idxarr[arr[i]];
      idxarr[arr[i]] = idx2;
      idx2 = arr[i];
      arr[i] = arr[idx1];
      arr[idx1] = idx2;
    }
  }
}

int main () {
  scanf("%d %d", &N, &K);
  for (int i=1; i<=N; i++) {
    scanf("%d", &arr[i]);
    idxarr[arr[i]] = i;
  }
  swap();
  for (int i=1; i<=N; i++) printf("%d ", arr[i]);
}
