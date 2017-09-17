#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
using namespace std;

int K, r, ans = 25;

int main () {
	scanf("%d", &K);
	for (int i=0; i<K; i++) {
		scanf("%d", &r);
		ans = max(ans, r);
	}
	return 0 * printf("%d\n", ans - 25);
}