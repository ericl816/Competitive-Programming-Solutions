#include <bits/stdc++.h>
#define ll long long 
#define INF 0x3f3f3f3f
#define d double
#define pll pair<ll, ll>
#define mp make_pair
#define f first
#define s second
using namespace std;

inline ll dist(pll a, pll b) {
	return (pow((b.s - a.s), 2) + pow((b.f - a.f), 2));
}

inline ll slope(pll a, pll b) {
	return (d) (b.s - a.s) / (b.f - a.f);
}

pll a, b, c;
ll slope1, slope2;

int main () {
	scanf("%lld %lld %lld %lld %lld %lld", &a.f, &a.s, &b.f, &b.s, &c.f, &c.s);
	if (dist(a, b) == dist(b, c)) { 
		if (((a.f + c.f) / 2.0 == b.f) && (a.s + c.s) / 2.0 == b.s) return 0 * printf("%s\n", "No");
		else return 0 * printf("%s\n", "Yes");
	}
	printf("%s\n", "No");
	return 0;
}