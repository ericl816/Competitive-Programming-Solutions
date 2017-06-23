#include <iostream>
#include <string.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define max(a,b) ((a) < (b) ? (b) : (a))
char _;
using namespace std;

const int MAXN = 201;
int dp [MAXN][MAXN];
int arr [MAXN];
int n;

inline int solve (int l, int r) {
  if (l == r) return 0;
  if (dp [l][r] != -1) return dp [l][r];
  int ans = 0;
  for (int i=l+1; i<r; i++) 
  ans = max(ans, solve (l, i) + solve (i, r) + arr [l] + arr[r] + arr[i]);
return dp [l][r] = ans;
}

int main () {
  while (true) {
    scan (n);
    if (n == 0) break;
    for (int i=0; i<n; i++) 
    scan (arr[i]);
    memset (dp, -1, sizeof dp);
    printf("%d\n", solve (0, n-1));
  }
}
