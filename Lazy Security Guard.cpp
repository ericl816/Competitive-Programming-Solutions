#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
using namespace std;

int N, ans;

int main () {
	scanf("%d", &N);
	int side = sqrt(N);
	int res = N - pow(side, 2);
	if (!res) ans = side * 4;
	else if (res <= side) ans = side * 4 + 2;
	else ans = side * 4 + 4;
	return 0 * printf("%d\n", ans);
}