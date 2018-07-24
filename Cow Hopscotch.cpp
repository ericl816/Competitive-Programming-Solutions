#include <bits/stdc++.h>
#define ll long long
#define MAXM 570010
#define MAXN 750
#define INF 0x3f3f3f3f
#define min(a, b) (a) < (b) ? (a) : (b)
#define max(a, b) (a) < (b) ? (b) : (a)
#define MOD 1000000007
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define mii map<int, int>
#define umii unordered_map<int, int>
using namespace std;

int N, M, K, Time, all;
int t[MAXM], s[MAXM];
int f[MAXN][MAXN], grid[MAXN][MAXN];
    
inline void Solve (int l, int r) {
    if (l == r) return;
    int mid = (l + r) >> 1;
    Solve(l, mid);
    Time++;
    all = 0;
    for (int j=1; j<=M; j++) {
        for (int i=r; i>=mid + 1; i--) {
            if (t[grid[i][j]] < Time) {
              t[grid[i][j]] = Time;
              s[grid[i][j]] = 0;
            }
            f[i][j] = ((f[i][j] + all - s[grid[i][j]]) % MOD + MOD) % MOD;
        }
        for (int i=l; i<=mid; i++) {
            if (t[grid[i][j]] < Time) {
              t[grid[i][j]] = Time;
              s[grid[i][j]] = 0;
            }
            s[grid[i][j]] = (s[grid[i][j]] + f[i][j]) % MOD;
            all = (all + f[i][j]) % MOD;
        }
    }
    Solve(mid + 1, r);
}

int main () {
    scanf("%d %d %d", &N, &M, &K);
    f[1][1] = 1;
    for (int i=1; i<=N; i++) for(int j=1; j<=M; j++) scanf("%d", &grid[i][j]);
    Solve(1, N);
    return !printf("%d\n", f[N][M]);
}