#include<bits/stdc++.h>
using namespace std;
int N, dp[402][402], sum[402], ans;
int main() {
    scanf("%d", &N);
    for(int i=1; i<=N; i++) {
        scanf("%d", &dp[i][i]);
        ans = max(ans, dp[i][i]);
        sum[i] = sum[i-1]+dp[i][i];
    }
    for(int gap=1; gap<N; gap++){
        for(int l=1; l + gap<=N; l++){
            int r = l + gap;
            for(int i=l, j=r; i + 1 <= j;){
                if(dp[l][i] && dp[j][r] && dp[l][i]==dp[j][r]){
                    if(i + 1 == j)
                        dp[l][r] = max(dp[l][r], dp[l][i] + dp[j][r]);
                    if(i + 1 < j && dp[i + 1][j - 1] != 0)
                        dp[l][r] = max(dp[l][r], dp[l][i] + dp[i + 1][j - 1] + dp[j][r]);
                    ans = max(ans, dp[l][r]);
                }
                if(sum[i] - sum[l-1] == sum[r] - sum[j - 1]) { 
                    i++; 
                    j--;
                }
                else if(sum[i] - sum[l - 1] < sum[r] - sum[j - 1]) i++;
                else j--;
            }
        }
    }
    printf("%d\n", ans);
}
