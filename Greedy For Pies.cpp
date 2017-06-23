#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define max(a,b) ((a) < (b) ? (b) : (a))
char _;
using namespace std;

int n, m, N[3002], M[102], dp[3002][102][102][2];

int solve (int i, int l, int r, int pos){
    if(i>n && l>r) return 0;
    if (dp[i][l][r][pos] ^ -1) return dp[i][l][r][pos];
    int & val = dp[i][l][r][pos];
    
    if(i <= n){
        val = max(val, solve(i+1, l, r, 0));
        if(pos ^ 1) val = max(val, N[i] + solve(i+1, l, r, 1));
    }
    
    if(l <= r){
        val = max(val, solve(i, l+1, r, 0));
        if(pos ^ 1) val = max(val, M[r] + solve(i, l, r-1, 1));
    }
    return dp[i][l][r][pos] = val;
}

int main() {
    scanf("%d", &n);
    for(int i=0; i<n; i++)
        scanf("%d", &N[i + 1]);
    scanf("%d", &m);
    for(int i=0; i<m; i++)
        scanf("%d", &M[i + 1]);
    sort(M + 1, M + m + 1);
    memset(dp, -1, sizeof(dp));
    printf("%d\n", solve(1, 1, m, 0));
}
