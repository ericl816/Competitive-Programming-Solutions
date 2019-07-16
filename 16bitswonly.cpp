#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;

ull N, A, B, P;
int main() {
	scanf("%llu", &N);
	while(N--) {
		scanf("%llu %llu %llu", &A, &B, &P);
		if (A * B == P) printf("%s", "POSSIBLE DOUBLE SIGMA\n");
		else printf("%s", "16 BIT S/W ONLY\n");
	}
}
