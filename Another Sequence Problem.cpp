#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define ull unsigned long long
#define MAXN 2510
#define MOD 1000000007
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
#define umii unordered_map<int, int>
#define DEBUG 1
#ifdef DEBUG
  #define D(x...) printf(x)
#else
  #define D(x...)
#endif
using namespace std;

/* 
 * How many ordered sequences of N non-negative integers are
 * such that each element is a member of the set
 * a1,a2,…aK and whose sum is at most M?
 * Interpret it as matrix multiplication, which is equivalent to exponentiation by squaring
 */

int M, K, a;
ll N, ans;
vll v(MAXN), freq(MAXN);

// Perform matrix multiplication
inline vll Multiply (vll &A, vll &B) {
  vll prod(A.size(), 0);
  for (size_t i=0; i<A.size(); i++) {
    for (size_t j=0; j<B.size(); j++) {
      if (i + j < prod.size()) prod[i + j] = (prod[i + j] + A[i] * B[j]) % MOD;
    }
  }
  return prod;
}

// Base is freq, exponent is N
inline void Pow () {
  v[0] = 1LL;
  while (N) {
    if (N & 1) v = Multiply(v, freq);
    freq = Multiply(freq, freq);
    N >>= 1;
  }
}

int main (int argc, char const *argv[]) {
  #ifdef NOT_DMOJ
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif // NOT_DMOJ
  cin.sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> N >> M >> K;
  for (int i=0; i<K; i++) {
    cin >> a;
    ++freq[a];
  }
  Pow();
  for (int i=0; i<=M; i++) ans = (ans + v[i]) % MOD;
  cout << ((ans + MOD) % MOD) << "\n";
  return 0;
}

/*
2 3 4
1 3 2 0
*/

/* 
 * Look for:
 * the exact constraints (multiple sets are too slow for n=10^6 :( ) 
 * special cases (n=1?)
 * overflow (ll vs int?)
 * array bounds
 */