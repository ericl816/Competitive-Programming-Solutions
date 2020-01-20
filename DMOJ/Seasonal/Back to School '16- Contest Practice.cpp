#include<bits/stdc++.h>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
using namespace std;
const int MAXN = 200000;
int P, Q, N, n, X, score, idx = 0, idx1 = 0, sco[MAXN], imp[MAXN];
int main () {
  scan(P);
  scan(Q);
  scan(N);
  sco[0] = 1;
  for (int i=0; i<P; i++) sco[i + 1] = Q * sco[i];
  for (int i=0; i<N; i++) {
    idx = 0;
    for (int j=0; j<P; j++) {
      scan(n);
      idx += sco[j] * (Q - n - 1);
    }
    imp[idx]++;
  }
  for (int i=0; i<=P; i++) {
    for (int j=0; j<sco[P]; j++) 
      if ((j / sco[i]) % Q) 
        imp[j] += imp[j - sco[i]];
  }
  scan(X);
  for (int i=0; i<X; i++) {
    idx1 = 0;
    for (int j=0; j<P; j++) {
      scan(score);
      idx1 += sco[j] * (Q - score - 1);
    }
    printf("%d\n", imp[idx1]);
  }
}