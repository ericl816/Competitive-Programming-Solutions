#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define MAXM 3010
#define MAXN 110
#define INF 0x3f3f3f3f
#define min(a, b) (a) < (b) ? (a) : (b)
#define max(a, b) (a) < (b) ? (b) : (a)
#define ll long long
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define mii map<int, int>
#define umii unordered_map<int, int>
using namespace std;

int N, M;
int A[MAXM], B[MAXN];
int DP[MAXM][MAXN][MAXN][2];

inline int Solve (int i, int l, int r, int pos) {
    if (i > N && l > r) return 0;
    int &val = DP[i][l][r][pos];
    if (~val) return val;
    if (i <= N) {
        val = max(val, Solve(i + 1, l, r, 0));
        if (pos == 0) val = max(val, A[i] + Solve(i + 1, l, r, 1));
    }
    if (l <= r) {
        val = max(val, Solve(i, l + 1, r, 0));
        if (pos == 0) val = max(val, B[r] + Solve(i, l, r - 1, 1));
    }
    return DP[i][l][r][pos] = val;
}

int main () {
    scan(N);
    for (int i=1; i<=N; i++) scan(A[i]);
    scan(M);
    for (int i=1; i<=M; i++) scan(B[i]);
    sort(B + 1, B + M + 1);
    memset(DP, -1, sizeof(DP));
    return !printf("%d\n", Solve(1, 1, M, 0));
}