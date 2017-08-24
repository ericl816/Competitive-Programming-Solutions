#include <bits/stdc++.h>
#define MAXN 100010

int N, arr[MAXN], num, ans;

int main() {
	scanf("%d", &N);
	for (int i=0; i<N; i++) scanf("%d", &arr[i]);
	std::sort(arr, arr + N);
	for (int i=0; i<N; i++) {
		if (num <= arr[i]) {
		  ans++;
			num += arr[i];
		}
	}
	printf("%d\n", ans);
}
