#include<cstdio>
#include<cstring>
#include<iostream>
#define ull unsigned long long 
const int MAXN = 1000005;
ull N, M, Q, Va, Vb, arr[MAXN], PSA[MAXN];
int main() {
    memset(arr, -1, sizeof(arr));
    scanf("%llu %llu %llu", &N, &M, &Q);
    for (int i = 0; i < N; i++) {
        scanf("%llu", &PSA[i]);
        arr[PSA[i]] = i;
        PSA[i] += PSA[i - 1];
    }
    for (int i=0; i<Q; i++) {
        scanf("%llu %llu", &Va, &Vb);
        printf("%s\n", M << 1 <= (PSA[arr[Vb]] - PSA[arr[Va] - 1]) ? "Enough" : "Not enough");
    }
}
