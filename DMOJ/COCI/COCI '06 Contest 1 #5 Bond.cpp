#include <bits/stdc++.h>
#define MAXN 20
using namespace std;

int N;
long double DP[1 << MAXN], arr[MAXN][MAXN];

int main() {
    cin >> N;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cin >> arr[i][j];
            arr[i][j] /= 100.0;
        }
    }
    DP[0] = 1.0;
    for (int i=1; i<(1 << N); i++) {
        int bits = __builtin_popcount(i);
        for (int j=0; j<N; j++) {
            if (i & (1 << j)) {
                DP[i] = max(DP[i], DP[i ^ (1 << j)] * arr[bits - 1][j]);
            }
        }
    }
    cout << fixed << setprecision(10) << DP[(1 << N) - 1] * 100.0 << "\n";
    return 0;
}