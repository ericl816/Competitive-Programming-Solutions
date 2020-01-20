#include<cstdio>
#include<cstring>
#include<iostream>
#define ll long long 
const int MAXN = 1000005;
ll N, M, Q, Va, Vb, arr[MAXN], PSA[MAXN];
int main() {
    memset(arr, -1, sizeof(arr));
    scanf("%lld %lld %lld", &N, &M, &Q);
    for (int i = 0; i < N; i++) {
        scanf("%lld", &PSA[i]);
        arr[PSA[i]] = i;
        PSA[i] += PSA[i - 1];
    }
    for (int i=0; i<Q; i++) {
        scanf("%lld %lld", &Va, &Vb);
        printf("%s\n", M << 1 <= (PSA[arr[Vb]] - PSA[arr[Va] - 1]) ? "Enough" : "Not enough");
    }
}