#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXN 20
#define INF 0x3f3f3f3f
#define min(a, b) (a) < (b) ? (a) : (b)
#define max(a, b) (a) < (b) ? (b) : (a)
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define mii map<int, int>
#define umii unordered_map<int, int>
using namespace std;

int n, m, s, d, l;
ll weights[MAXN][MAXN];
ll DP[1 << MAXN][MAXN];

inline ll Solve (ll x, ll y) {
  if (y == n - 1) return 0;
  ll &res = DP[x][y];
  if (~res) return res;
  ll curr = -INF;
  for (int i=0; i<n; i++) {
    if (!weights[y][i] || x & 1 << i) continue;
    curr = max(curr, Solve(x | 1 << i, i) + weights[y][i]);
  }
  return res = curr;
}

int main () {
  #ifdef NOT_DMOJ
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif // NOT_DMOJ
  cin.sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i=0; i<m; i++) {
    cin >> s >> d >> l;
    weights[s][d] = l;
  }
  memset(DP, -1, sizeof(DP));
  cout << Solve(1, 0) << "\n";
  return 0;
}