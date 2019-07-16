#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define ull unsigned long long
#define MAXM 1000001
#define MAXN 100001
#define MOD 999983
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

int N, M, x, v;
int arr[MAXN];
ll BIT1[MAXN], BIT2[MAXM];
char ch;

inline void Update1 (int idx, int val) {
  for (; idx<MAXN; idx += idx & -idx) BIT1[idx] += val;
}

inline void Update2 (int idx, int val) {
  for (; idx<MAXM; idx += idx & -idx) BIT2[idx] += val;
}

inline void Update (int idx, int val) {
  Update1(idx, val - arr[idx]);
  Update2(arr[idx], -1);
  arr[idx] = val;
  Update2(arr[idx], 1);
}

inline ll Query1 (int idx) {
  ll ans = 0;
  for (; idx; idx -= idx & -idx) ans += BIT1[idx];
  return ans;
}

inline ll Query1 (int x, int y) {
  return Query1(y) - Query1(x - 1);
}

inline ll Query2 (int idx) {
  ll ans = 0;
  for (; idx; idx -= idx & -idx) ans += BIT2[idx];
  return ans;
}

inline ll Query2 (int x, int y) {
  return Query2(y) - Query2(x - 1);
}

int main () {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> N >> M;
  for (int i=1; i<=N; i++) {
    cin >> arr[i];
    Update1(i, arr[i]);
    Update2(arr[i], 1);
  }
  for (int i=0; i<M; i++) {
    cin >> ch;
    if (ch == 'C') {
      cin >> x >> v;
      Update(x, v);
    }
    else if (ch == 'S') {
      cin >> x >> v;
      ll ans = Query1(x, v);
      cout << ans << "\n";
      Update(1, ans % MOD);
    }
    else {
      cin >> v;
      ll ans = Query2(v, MAXM - 1);
      cout << ans << "\n";
      ll res = arr[1] % (ans + 1);
      Update(1, res);
    }
  }
}

/*
5 5
2 9 2 4 1
C 2 4
S 2 4
Q 4
Q 3
S 1 5

Ans:
10
3
2
13
*/