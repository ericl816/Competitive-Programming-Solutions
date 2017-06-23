#include <bits/stdc++.h>
#define ull unsigned long long 
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define min(a,b) ((a) > (b) ? (b) : (a))
char _;
using namespace std;

struct Cards {
  ull c, d;
};
int n;
ull c, d, dp[5005][5005];
Cards arr [5005];

ull solve (int a, int b) {
    if (n - 1 <= b)
        return 0;
    if (~dp[a][b])
        return dp[a][b];
    if (a ^ b) return dp[a][b] = min(arr[a].c + solve(a + 1, b + arr[a].d), solve(a + 1, b));
    if (a == b)
        return dp[a][b] = arr[a].c + solve(a + 1, b + arr[a].d);
}

int main () {
    scan(n);
    memset(dp, -1, sizeof(dp));
    for (int i=0; i<n; i++) {
        scan(arr[i].c); scan(arr[i].d);
}
        printf("%llu\n", solve(0, 0));
}
