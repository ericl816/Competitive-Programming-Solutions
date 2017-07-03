#include<bits/stdc++.h>
using namespace std;

const int MAXN = 110;
int N, DP[MAXN][MAXN], arr[MAXN][MAXN]; 

int solve(int a, int b) {
    int &ret = DP[a][b];
    if (~DP[a][b]) return ret;
    if (N - 1 == a) ret = arr[a][b];
    else 
    ret = arr[a][b] + max(solve(a + 1, b), solve(a + 1, b + 1));
    return DP[a][b] = ret;
}

int main() {
    memset(DP, -1, sizeof(DP));
    scanf("%d", &N);
    for (int i=0; i<N; i++) 
        for (int j=0; j<=i; j++) 
            scanf("%d", &arr[i][j]);
    printf("%d\n", solve(0, 0));
}
