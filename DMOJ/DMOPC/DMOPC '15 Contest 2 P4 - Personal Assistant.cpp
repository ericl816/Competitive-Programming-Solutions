#include<iostream>
#include<algorithm>
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define max(a,b) ((a) < (b) ? (b) : (a))
#define ll long long
char _;
using namespace std;

struct Anime{
  ll r, l, h;
};

const int MAXN = 100005;
ll n, curr, dp[MAXN];
Anime arr [MAXN];

ll solve (int cur) {
  if (~dp[cur]) return dp[cur];
  if (cur >= n) return 0;
  int lo = cur + 1, hi = n - 1;
  ll &next = dp[cur];
  while (lo <= hi) {
    int mid = (lo + hi) >> 1;
    if (arr[mid].r < arr[cur].r + arr[cur].l) lo = mid + 1;
    else hi = mid - 1;
  }
  if (lo == n) return next = max(arr[cur].h, (solve(cur + 1)));
  return next = max(max(solve(cur + 1), solve(lo) + arr[cur].h), dp[cur]);
}

int main () {
scan(n);
memset(dp, -1, sizeof(dp));
for (int i=0; i<n; i++) {
scan(arr[i].r); scan(arr[i].l); scan(arr[i].h);
}
printf("%lld\n", solve(0));
}