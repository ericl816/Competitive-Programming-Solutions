#include <bits/stdc++.h>
#define ull unsigned long long

int setbits(ull a) {
  return __builtin_popcountll(a);
}

ull n;
int main () {
  scanf("%llu", &n);
  printf("%llu\n", setbits(n));
}
