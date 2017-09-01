#include <bits/stdc++.h>
#define ll long long
#define MAXN 1000
using namespace std;

int k, sum;
char ch = 'a';

int main () {
	scanf("%d", &k);
	if (k == 0) return 0 * printf("%c\n", ch);
	for (int i=MAXN; i>=0;) {
		sum = (i * (i + 1)) >> 1;
		if (k >= sum) {
			k -= sum;
			for (int j=0; j<i + 1; j++) printf("%c", ch);
			ch++;
			}
			else if (k == 0) break;
			else i--;
	}
}
