#include<bits/stdc++.h>
#define MAXN 3010
using namespace std;

int N, arr[MAXN];

int main() {
    scanf("%d", &N);
    for(int i=0; i<(N << 1); i++) scanf("%d", &arr[i]);
    sort(arr, arr + (N << 1));
    printf("%s\n", arr[N] ^ arr[N - 1] ? "YES" : "NO"); 
}
