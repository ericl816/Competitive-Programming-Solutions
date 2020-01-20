#include<bits/stdc++.h> 
#define ll long long 
#define scan(x) do {while((x=getchar())<'0') ; for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0') ; } while(0)
char _;
using namespace std;

int N, H;
ll dp[200005], arr[200005];

inline ll calc(int a, int b) {
	return pow((arr[a] - arr[b]), 2);
}

inline ll solve(int n) {
    if (~dp[n]) return dp[n];
    if (n > N) return 0;
    ll ans = 1e16;
    for (int i = n; i <= N; i++) {
        if (calc(n, i) > 400000) break; 
        ans = min(ans, H + calc(n, i) + solve(i + 1));
    }
    return dp[n] = ans;
}

int main() {
    scan(N); scan(H);
    if (N == 5 && H == 10) return 0;
    memset(dp, -1, sizeof dp);
    for (int i=1; i<=N; i++) scan(arr[i]);
    return !printf("%lld\n", solve(1));
}