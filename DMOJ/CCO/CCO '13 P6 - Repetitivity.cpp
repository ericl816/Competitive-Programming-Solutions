#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXN 10010
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

int M, n;
int dp[MAXN][MAXN];
string ch;

int main () {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> ch >> M;
    n = ch.size();
    for (int i=0; i<=n; i++) dp[0][i] = dp[i][0] = 1;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            dp[i + 1][j + 1] = (dp[i][j + 1] + dp[i + 1][j]) % M;
            if (ch[i] ^ ch[j]) dp[i + 1][j + 1] = (dp[i + 1][j + 1] - dp[i][j] + M) % M;
        }
    }
    cout << dp[n][n] << "\n";
    return 0;
}