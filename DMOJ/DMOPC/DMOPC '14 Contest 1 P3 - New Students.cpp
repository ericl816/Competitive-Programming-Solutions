#include <bits/stdc++.h>
using namespace std;

int N, M;
double sum;

int main () {
    scanf("%d", &N);
    for (int i=0, x; i<N; i++) {
        scanf("%d", &x);
        sum += 1.0 * x;
    }
    scanf("%d", &M);
    for (int i=0, x; i<M; i++) {
        scanf("%d", &x);
        sum += 1.0 * x;
        printf("%.3f\n", sum / (N + i + 1));
    }
    return 0;
}