#include <stdio.h>
#define ll long long 
using namespace std;

int n, k, a, sum, rem;

int main () {
	scanf("%d %d", &n, &k);
	for (int i=1; i<=n; i++) {
		scanf("%d", &a);
		sum += a;
		if (sum >= 8) {
			sum -= 8;
			k -= 8;
		}
		else {
			k -= sum;
			sum = 0;
		}
		if (k <= 0) {
		  printf("%d\n", i);
		  return 0;
		}
	}
	printf("%d\n", -1);
}
