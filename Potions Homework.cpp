#include <bits/stdc++.h>
#define ll long long
#define MAXN 100010
#define MOD 10007
#define mp make_pair
#define vi vector<int>
using namespace std;

bool compare (int x, int y) {
	return y < x;
}

int N, val;
ll lazy[MAXN], diff[MAXN], ans;


int main () {
	scanf("%d", &N);
	for (int i=1; i<=N; i++) {
		scanf("%d", &val);
		lazy[i] = diff[i] = val;
	}
	sort(lazy + 1, lazy + N + 1);
	sort(diff + 1, diff + N + 1, compare);
	for (int i=1; i<=N; i++) ans = (ans + (lazy[i] * diff[i])) % MOD;
	printf("%lld\n", ans);
	return 0;
}
