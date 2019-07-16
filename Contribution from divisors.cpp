#include <bits/stdc++.h>
#define ll long long
#define MAXN 1000010
using namespace std;

int q, n, ans[MAXN];

int F (int n) {
	int val = 0;
	while(n) {
		int res = n % 10;
		n /= 10;
		if (res & 1) val += res;
	}
	return val;
}

int main() {
	for (int i=1; i<MAXN; i++) {
		int res = F(i);
		for (int j=i; j<MAXN; j+=i) ans[j] += res;
	}
	scanf("%d", &q);
	while (q--) {
		scanf("%d", &n);
		printf("%d\n", ans[n]);
	}
	return 0;
}
