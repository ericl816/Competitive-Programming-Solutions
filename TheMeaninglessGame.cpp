#include <bits/stdc++.h>
#define ll long long 
using namespace std;

ll n, a, b, cubrt, div1, div2;

int main() {
	scanf("%lld", &n);
	while (n--) {
		scanf("%lld %lld", &a, &b);
		cubrt = cbrt(a * b);
		div1 = a / cubrt;
		div2 = b / cubrt;
		printf("%s\n", (pow(div1, 2) * div2 == a && pow(div2, 2) * div1 == b ? "Yes" : "No"));
	}
}