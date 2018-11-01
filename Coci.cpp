#include <bits/stdc++.h>
#define ll long long
#define MAXM 660
#define MAXN 500010
#define INF 0x3f3f3f3f
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define mii map<int, int>
#define umii unordered_map<int, int>
using namespace std;

int N, hi, lo;
int a[MAXN], b[MAXN];
int grid[MAXM][MAXM], PSA[MAXM][MAXM];

inline int Query (int x1, int y1, int x2, int y2) {
    if (x2 < 0 || y2 < 0) return 0;
    int val = PSA[x2][y2];
    if (x1 > 0) val -= PSA[x1 - 1][y2];
    if (y1 > 0) val -= PSA[x2][y1 - 1];
    if (x1 > 0 && y1 > 0) val += PSA[x1 - 1][y1 - 1];
    return val;
}

int main () {
    scanf("%d", &N);
    for (int i=0; i<N; i++) {
      scanf("%d %d", &a[i], &b[i]);
      grid[a[i]][b[i]]++;
    }
    for (int i=0; i<=650; i++) {
      for (int j=0; j<=650; j++) {
        PSA[i][j] = grid[i][j];
        if (i > 0) PSA[i][j] += PSA[i - 1][j];
        if (j > 0) PSA[i][j] += PSA[i][j - 1];
        if (i > 0 && j > 0) PSA[i][j] -= PSA[i - 1][j - 1];
      }
    }
    for (int i=0; i<N; i++) {
      hi = Query(a[i] + 1, b[i] + 1, 650, 650) + 1;
      lo = N - Query(0, 0, a[i] - 1, b[i] - 1) - grid[0][b[i]] * (a[i] == 650) - grid[a[i]][0] * (b[i] == 650);
      printf("%d %d\n", hi, lo);
    }
}
