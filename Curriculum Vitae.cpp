#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define MAXN 110
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define vi vector<int>
#define pb push_back
#define max(a, b) (a) < (b) ? (b) : (a)
#define min(a, b) (a) < (b) ? (a) : (b)
using namespace std;

int n, arr[MAXN];
int maxx = -INF;

int main () {
	scanf("%d", &n);
	for (int i=1; i<=n; i++) scanf("%d", &arr[i]);
	for (int i=0; i<=n ;i++) {
		int sum = 0;
		for (int j=1; j<=i; j++) sum += (arr[j] == 0);
		for (int j= i + 1; j<=n; j++) sum += (arr[j] == 1);
		maxx = max(maxx, sum);
	}
	printf("%d\n", maxx);
	return 0;
}