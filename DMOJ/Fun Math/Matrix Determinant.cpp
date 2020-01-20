#include<bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define ll long long
char _;
using namespace std;
const int MOD = (ll) 1e9 + 7;
ll N, arr[510][510], det = 1;
ll fpow (ll a, ll b) {
  if (b == 0) return 1;
  if (b == 1) return a;
  if (!(b & 1)) return fpow(a * a % MOD, b >> 1);
  return a * fpow(a * a % MOD, b >> 1 % MOD) % MOD;
}
int main () {
  scan(N);
  for (int i=0; i<N; i++) {
    for (int j=0; j<N; j++) {
      scanf("%lld", &arr[i][j]);
      if (arr[i][j]) arr[i][j] += MOD;
    }
  }
  for (int i=0; i<N; i++) {
    int idx = i;
    for (int j=i + 1; j<N; j++) 
      if (arr[idx][i] < arr[j][i]) idx = j;
      if (idx ^ i) {
        det *= -1;
        swap(arr[i], arr[idx]);
      }
      for (int j=i + 1; j<N; j++) {
        ll val =  arr[j][i] * fpow(arr[i][i] % MOD, MOD - 2 % MOD) % MOD;
        for (int k=i; k<N; k++) arr[j][k] = ((arr[j][k] % MOD - val % MOD * arr[i][k] % MOD) % MOD + MOD) % MOD;
      }
  }
  for (int i=0; i<N; i++) det = (det % MOD * arr[i][i] % MOD) % MOD;
  return !printf("%lld\n", (det + MOD) % MOD);
}