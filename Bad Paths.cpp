#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long 
using namespace std;

const int MAXN = 10000010, MOD = 1e9 + 7;
ll N, x, arr[MAXN], fac[MAXN], num;

ll fpow (ll x, ll y, ll MOD) {
  if (y == 0) return 1;
  else if (y == 1) return x;
  else if (y & 1) return x * fpow(x * x % MOD, y >> 1, MOD) % MOD;
  else return fpow(x * x % MOD, y >> 1, MOD); 
}

void PreProcess () {
  fac[0] = 1;
  arr[0] = 1;
  for (int i=0; i<1000000; i++) {
    fac[i + 1] = ((i + 1) * fac[i]) % MOD;
    arr[i + 1] = (fpow(fac[i + 1], MOD - 2, MOD) % MOD + arr[i]) % MOD;
  }
}

int main () {
  PreProcess();
  scan(N);
  for (int i=0; i<N; i++) {
    scan(x);
    num = ((((arr[x] * fac[x] - (x + 1)) % MOD - (x * (x - 1)) % MOD) % MOD + MOD) % MOD) * fpow(2, MOD - 2, MOD) % MOD;
    printf("%lld\n", num);
  }
}
