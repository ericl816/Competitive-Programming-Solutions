#include <bits/stdc++.h>
#define ll long long

ll R, C, K, len1, len2, ans;

int main() {
	scanf("%lld %lld %lld", &R, &C, &K);
	len1 = (ll) sqrt(K);
	if (len1 > R && len1 > C) len1 = std::min(len1, std::max(R, C));
	else len1 = std::min(len1, std::min(R, C));
	len2 = (ll) ceil(((double) K) / len1);
	ans = 2 * (len1 + len2);
	printf("%lld\n", ans);
}