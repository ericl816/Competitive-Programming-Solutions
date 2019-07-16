#include<bits/stdc++.h>
using namespace std;
int N, M, bit;
int main () {
  scanf("%d %d", &N, &M);
  for (int i=0; i<N; i++) {
    bit = ((i >> 1) ^ i) << 10;
    for (int i=0; i<M; i++) cout << (((i >> 1) ^ i) | bit) << " ";
    cout << "\n";
  }
}
