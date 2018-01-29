#include <bits/stdc++.h>

using namespace std;

int N, M;
double sum = 0;

int main () {
    scanf("%d", &N);
    for (int i=0, x; i<N; i++) { scanf("%d", &x); sum += (double) x; }
    scanf("%d", &M);
    for (int i=0, x; i<M; i++){
        scanf("%d", &x);
        sum += x;
        printf("%.3f\n", sum / (N + i + 1));
    }
}