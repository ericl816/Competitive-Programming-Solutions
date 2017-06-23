#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <vector>

#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)

char _;

using namespace std;

int N, A[100000], T[100000], F[100001];

void update(int n, int m){
	while(n <= 100001){
		F[n] += m;
		n += n & (-n);
	}
}

int query(int n){
	int c = 0;
	while(n > 0){
		c += F[n];
		n -= n & (-n);
	}
	return c;
}

int main(){
	long count = 0;
	scan(N);
	for(int i = 0; i < N; i++)
		scan(A[i]);
	for(int i = 0; i < N; i++)
		T[i] = A[i];
	sort(T, T + N);
	for(int i = 0; i < N; i++)
		A[i] = lower_bound(T, T + N, A[i]) - T + 1;

	for(int i = 0; i < N; i++){
		update(A[i], 1);
		count += (i + 1) - query(A[i]) + 1;
	}

	printf("%.2lf", (double) count/N);
}
