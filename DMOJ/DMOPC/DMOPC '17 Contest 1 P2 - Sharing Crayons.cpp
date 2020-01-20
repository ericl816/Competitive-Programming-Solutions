#include <bits/stdc++.h>
#define ll long long
#define MAXN 100010
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define umii unordered_map<int, int>
#define mii map<int, int>
using namespace std;

int N, M, crayons[MAXN];
mii cnt;
ll psa[MAXN], ans;

int main () {
	scanf("%d %d", &N, &M);
	for (int i=1; i<=N; i++) {
		scanf("%d", &crayons[i]);
		psa[i] = (psa[i - 1] + crayons[i]) % M;
	}
	cnt[0] = 1;
	for (int i=1; i<=N; i++) {
		if (!cnt.count(psa[i])) cnt[psa[i]] = 1;
		else {
			ans += cnt[psa[i]];
			cnt[psa[i]] = cnt[psa[i]] + 1;
		}
	}
	printf("%lld\n", ans);
	return 0;
}