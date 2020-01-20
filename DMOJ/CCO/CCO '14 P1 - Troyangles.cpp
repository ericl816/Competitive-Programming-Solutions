#include <bits/stdc++.h>

char input[2005][2005];
int M,dp[2005][2005],sum;
using namespace std;

int main() {
    cin>>M;
    for(int i = 1;i <=M;i++)
        for(int j = 1; j <= M;j++)
            cin>>input[i][j];
            
            
    
    for(int i = M;i>=1;i--)
    {
        for(int j = 1 ; j <=M;j++)
        {
            if(input[i][j] != '#' )
            {
                dp[i][j] = 0;
             
            }
             
            else
            {
                dp[i][j] = min(dp[i+1][j],min(dp[i+1][j-1],dp[i+1][j+1])) + 1;
            }
            sum+=dp[i][j];
            
        }
    }
    cout<<sum;
    return 0;
}