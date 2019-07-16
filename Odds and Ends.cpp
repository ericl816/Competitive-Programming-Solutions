#include <bits/stdc++.h>
#define ll long long
#define MAXN 110
using namespace std;

int N, arr[MAXN];
int main () {
	scanf("%d", &N);
	for (int i=0; i<N; i++) scanf("%d", &arr[i]);
	if (arr[0] & 1 && arr[N - 1] & 1 && N & 1) printf("%s\n", "Yes");
	else printf("%s\n", "No");
}