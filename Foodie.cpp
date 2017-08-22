#include <bits/stdc++.h>
#define ll long long 
#define bit bitset
#define MAXN 1000010
using namespace std;

int C, N, arr[MAXN];
bit<MAXN> DP;

int main () {
    scanf("%d %d", &C, &N);
	DP.set(0);
	for (int i=0; i<N; i++) {
	  scanf("%d", &arr[i]);
	  if ((DP & (DP << arr[i])) != 1) DP |= (DP << arr[i]);
	}
	for (int i=C - 1; i>=0; i--) {
	  if (DP[i]) {
	    printf("%d\n", i);
	    return 0;
		}
	}
	printf("%d\n", 0);
}
