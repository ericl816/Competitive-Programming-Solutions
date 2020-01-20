#include <stdio.h>
#include<iostream>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
using namespace std;
	
int main () {
	int n, t;
	for (int i = 0; i < 10; i++) {
		scan(n); scan(t);
		printf ("%d\n", (n << 1) - 1);
	}
}