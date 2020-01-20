#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC optimize "omit-frame-pointer"
#pragma GCC optimize "prefetch-loop-arrays"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,aes,sse4a,sse4.1,sse4.2,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define ull unsigned long long
#define MAXN 300010
#define MOD 1000000007
#define EPS 0.00000001
#define INF 0x3f3f3f3f
#define min(a, b) (a) < (b) ? (a) : (b)
#define max(a, b) (a) < (b) ? (b) : (a)
#define vi vector<int>
#define vll vector<ll>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define mii map<int, int>
#define umii unordered_map<int, int>w
#define allof(x) x.begin(), x.end()
#define DEBUG 1
// #define NOT_DMOJ 0
#ifdef DEBUG
  #define D(x...) printf(x)
#else
  #define D(x...)
#endif
using namespace std;

inline int GCD (int a, int b) { return b == 0 ? a : GCD(b, a % b); }
inline int LCM (int a, int b) { return a * b / GCD(a, b); }
inline ll PowMod (ll a, ll b, ll mod) { ll val = 1; while (b) { if (b & 1) val = (val * a) % mod; a = (a * a) % mod; b >>= 1; } return val; }

int n, k;
int a[MAXN];
long double s[MAXN];

inline bool Valid (long double P) {
  s[0] = 0;
  for (int i=1; i<=n; i++) s[i] = s[i - 1] + a[i] - P;
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
  while (hi - lo >= EPS) {
    long double mid = (lo + hi) / 2.0;
    if (Valid(mid)) lo = mid; 
    else hi = mid;
  }
  return !printf("%.6lf\n", (double) lo);
}