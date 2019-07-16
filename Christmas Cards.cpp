#include <bits/stdc++.h>
#define ull unsigned long long
#define MAXN 5010 
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define min(a,b) ((a) > (b) ? (b) : (a))
#define f first
#define s second
char _;
using namespace std;

int n;
pair<ull, ull> arr[MAXN];
ull c, d;
ull DP[MAXN][MAXN];

ull Solve (int a, int b) {
    if (n - 1 <= b) return 0;
    if (~DP[a][b]) return DP[a][b];
    if (a ^ b) return DP[a][b] = min(arr[a].f + Solve(a + 1, b + arr[a].s), Solve(a + 1, b));
    if (a == b) return DP[a][b] = arr[a].f + Solve(a + 1, b + arr[a].s);
}

int main () {
    scan(n);
    memset(DP, -1, sizeof(DP));
    for (int i=0; i<n; i++) {
        scan(arr[i].f); 
        scan(arr[i].s);
    }
    printf("%llu\n", Solve(0, 0));
}