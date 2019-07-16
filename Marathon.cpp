#include <bits/stdc++.h>

#define MAXN 500010
using namespace std;

int N, Q, a, b, arr[MAXN], PSA[MAXN];
int main () {
	scanf("%d %d", &N, &Q);
	for (int i=0; i<N; i++) {
	scanf("%d", &arr[i]);
	PSA[i + 1] = PSA[i] + arr[i];
	}
	for (int i=0; i<Q; i++) {
	scanf("%d %d", &a, &b);
	printf("%d\n", PSA[a - 1] + PSA[N] - PSA[b]);
	}
}
