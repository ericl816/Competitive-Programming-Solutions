#include <bits/stdc++.h>
using namespace std;

const int MAXN = 115, MAXY = 15;
int n, q, c, x, y, s, ans;
int arr[MAXN][MAXN][MAXY];

int main() {
    scanf("%d %d %d", &n, &q, &c);
    for (int i=0; i<n; i++) {
        scanf("%d %d %d", &x, &y, &s);
        arr[x][y][s]++;
    }
    for (int p=0; p<=c; p++) 
        for (int i=1; i<MAXN; i++) 
            for (int j=1; j<MAXN; j++) 
                arr[i][j][p] += arr[i - 1][j][p] + arr[i][j - 1][p] - arr[i - 1][j - 1][p];
    
    for (int i=0; i<q; i++) {
        int t, x1, y1, x2, y2;
        scanf("%d %d %d %d %d", &t, &x1, &y1, &x2, &y2);
        ans = 0;
        for (int p=0; p<=c; p++) ans += ((p + t) % (c + 1)) * (arr[x2][y2][p] - arr[x1 - 1][y2][p] - arr[x2][y1 - 1][p] + arr[x1 - 1][y1 - 1][p]);
        printf("%d\n", ans);
    }
}
