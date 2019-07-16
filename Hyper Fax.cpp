#include <bits/stdc++.h>

using namespace std;
struct Location { 
  int x, d; 
} arr[2002];

const int MAXN = 2001;
int n, dp [2][MAXN][MAXN], prefix [MAXN], ans=0;

bool cmp(Location x, Location y) {
  return x.x < y.x; 
}

int main(){
    scanf("%d", &n);
    for(int i=1; i<=n; i++) {
        scanf("%d %d", &arr[i].x, &arr[i].d);
    }
    sort(arr+1, arr+n+1, cmp);
    for(int i=1; i<=n; i++){
        prefix[i] = prefix[i-1] + arr[i].d;
        if(arr[i].x == 0) 
        dp[1][i][i] = dp[0][i][i] = arr[i].d;
    }
   
   for(int i=1; i<n; i++){
        for(int j=1; j+i <= n; j++){
            int r = j+i;
            int dl = max(dp[0][j+1][r], dp[1][j+1][r] - (arr[r].x - arr[j+1].x));
            if(dl >= arr[j+1].x - arr[j].x)
                dp[0][j][r] = max(dp[0][j][r], dl - (arr[j+1].x - arr[j].x) + arr[j].d);
            int dr = max(dp[1][j][r-1], dp[0][j][r-1] - (arr[r-1].x - arr[j].x));
            if(dr >= arr[r].x - arr[r-1].x)
                dp[1][j][r] = max(dp[1][j][r], dr - (arr[r].x-arr[r-1].x) + arr[r].d);
        }
    }
    for(int i=1; i<=n; i++)
        for(int j=i; j<=n; j++)
            if(dp[0][i][j] > 0 || dp[1][i][j] > 0)
                ans = max(ans, prefix[j] - prefix[i-1]);
    printf("%d\n", ans);
}
