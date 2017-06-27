#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[100010], b[100010];
char ch[100010];
ll N, T, i, j;

int main() {
	scanf("%lld %lld %s", &N, &T, ch);
	 for (int i=0; i<N; i++) a[i] = ch[i] - '1';
	for(int i=63; i>=0; i--) {
		if(T & ((ll) 1 << i)) {
			ll temp = ((ll) 1 << i) % N;
			for(int j=0; j<N; j++) b[j] = a[(j - temp + N) % N] ^ a[(j + temp) % N];
			for(j=0; j<N; j++) a[j] = b[j];
		}
	}
	for(int i=0; i<N; i++) printf("%d", (a[i]) ? 1 : 0);
}
