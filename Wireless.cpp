#include<bits/stdc++.h>
using namespace std;
int diff[30005][1005];
int M, N, K, B, R, row, col, maxb = 0, num = 0;

int main() {
scanf("%d\n %d\n %d", &M, &N, &K);
	for (int i=0; i<K; i++) {
	    scanf("%d %d %d %d", &col, &row, &R, &B);
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
            if (diff[i][j] == maxb) num++;
            if (maxb < diff[i][j]) {
                maxb = diff[i][j];
                num = 1;
            }
        }
    }
	printf("%d\n%d\n", maxb, num);
}
