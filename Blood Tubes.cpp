#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXN 500010
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

int n, x;
int BIT1[MAXN], BIT2[MAXN];
ll sum;

inline void Update (int i, int val, int *BIT) {
  for (; i<MAXN; i+=i & -i) BIT[i] += val;
}

inline ll Query (int i, int *BIT) {
  ll ans = 0;
  for (; i; i-=i & -i) ans += BIT[i];
  return ans;
}

int main () {
  #ifdef NOT_DMOJ
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif // NOT_DMOJ
  cin.sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  scanf("%d", &n);
  for (int i=0; i<n; i++){
    scanf("%d", &x);
    sum += min(Query(x, BIT1), Query(n - x + 1, BIT2));
    Update(x, 1, BIT1);
    Update(n - x + 1, 1, BIT2);
  }
  return !printf("%lld\n", sum);
}
