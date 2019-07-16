#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXN 410
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

int N, ans;
int sum[MAXN];
int dp[MAXN][MAXN];

// Use a 2-pointer approach to solve the problem
// Overall Time Complexity: O(N ^ 3)

int main () {
    #ifdef NOT_DMOJ
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif // NOT_DMOJ
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    scanf("%d", &N);
    for(int i=1; i<=N; i++) {
        scanf("%d", &dp[i][i]);
        ans = max(ans, dp[i][i]);
        sum[i] = sum[i - 1] + dp[i][i];
    }
    for (int gap=1; gap<N; gap++) {
        for (int l=1; l + gap<=N; l++) {
            int r = l + gap;
            for (int i=l, j=r; i + 1 <= j;) {
                if (dp[l][i] && dp[j][r] && dp[l][i] == dp[j][r]) {
                    if (i + 1 == j) dp[l][r] = max(dp[l][r], dp[l][i] + dp[j][r]);
                    if (i + 1 < j && dp[i + 1][j - 1] != 0) dp[l][r] = max(dp[l][r], dp[l][i] + dp[i + 1][j - 1] + dp[j][r]);
                    ans = max(ans, dp[l][r]);
                }
                if (sum[i] - sum[l - 1] == sum[r] - sum[j - 1]) { 
                    i++; 
                    j--;
                }
                else if (sum[i] - sum[l - 1] < sum[r] - sum[j - 1]) i++;
                else j--;
            }
        }
    }
    return !printf("%d\n", ans);
}
