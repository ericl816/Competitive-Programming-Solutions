#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define max(a,b) ((a) < (b) ? (b) : (a))
#define MAXN 300010
#define INF 0x3f3f3f3f
using namespace std;

long double s[MAXN];
int a[MAXN];
int n, k;

inline bool can (long double P) {
  s[0] = 0;
  for (int i=1; i<=n; i++) s[i] = s[i-1] + a[i] - P;
  long double mins = 0;
  for (int i=k; i<=n; i++) {
    if (s[i] >= mins) return 1;
    mins = min(mins, s[i - k + 1]);
  }
  return 0;
}

int main () {
  scan(n); scan(k);
  for (int i=1; i<=n; i++) scan(a[i]);
  long double lo = 0, hi = 2000000;
  while (hi - lo >= 0.001) {
    long double mid = (lo + hi) / 2.0;
    if (can(mid)) lo = mid; 
    else hi = mid;
  }
  return !printf("%.6lf\n", (double) lo);
}