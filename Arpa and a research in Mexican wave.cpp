#include <iostream>
#include <stdio.h>
#define ll long long
using namespace std;

int n, k, t;

int main () {
	scanf("%d %d %d", &n, &k, &t);
	if (t > n) printf("%d\n", n - t + k);
	else if (t > k && t <= n) printf("%d\n", k);
	else if (t <= k) printf("%d\n", t);
	return 0;
}
