#include <bits/stdc++.h>
#define ll long long
#define MAXM 1010
#define MAXN 30010
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

int M, N, K, B, R, row, col, maxbitrate, num;
int diff[MAXN][MAXM];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> M >> N >> K;
    for (int i=0; i<K; i++) {
        cin >> row >> col >> R >> B;
        swap(row, col);
        for (int j=max(1, col - R); j<=min(N, col + R); j++) {
            int left = max(1, row - (int) sqrt(pow(R, 2) - (col - j) * (col - j)));
            int right = min(M, row + (int) sqrt(pow(R, 2) - (col - j) * (col - j)));
            diff[left][j] += B;
            diff[right + 1][j] -= B;
        }
    }
    for (int i=1; i<=M; i++) {
        for (int j=1; j<=N; j++) {
            diff[i][j] += diff[i - 1][j];
            if (diff[i][j] == maxbitrate) num++;
            if (diff[i][j] > maxbitrate) {
                maxbitrate = diff[i][j];
                num = 1;
            }
        }
    }
    cout << maxbitrate << endl << num << endl;
}