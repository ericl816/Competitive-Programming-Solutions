#include<bits/stdc++.h> 
#define INF -99999999999
#define ll long long
using namespace std;
ll n, m, s, d, l, dp[1 << 20][20], mask[50][50];

ll Solve (ll a, ll b) {
  ll &curr = dp[a][b];
  if (~curr) return curr;
  if (b == n - 1) return 0;
    curr = INF;
    for (int i=0; i<n; i++) {
      if (!mask[b][i] || (a & 1 << i)) continue; //If bit is already set 
   curr = max(curr, Solve(a | 1 << i, i) + mask[b][i]); 
}
  return dp[a][b] = curr;
}

int main () {
  scanf("%d %d", &n, &m);
  for (int i=0; i<m; i++) {
    scanf("%d %d %d", &s, &d, &l);
    mask[s][d] = l;
  }
    memset(dp, -1, sizeof(dp));
  printf("%lld\n", Solve(1, 0));
}
