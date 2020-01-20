#include <bits/stdc++.h>
#define ll long long
#define MAXN 100010
#define INF 0x3f3f3f3f
#define min(a, b) (a) < (b) ? (a) : (b)
#define max(a, b) (a) < (b) ? (b) : (a)
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define mii map<int, int>
#define umii unordered_map<int, int>
using namespace std;

ll h, m, s;
ll t, res = 12 * 3600;

int main() {
	scanf("%lld %lld %lld", &h, &m, &s);
	h %= 12;
	m %= 12 * 60;
	s %= res;
	t = (h * 3600) % res + (m * 60) % res + s;
	t %= res;
	t = res - t;
	if (t / 3600 == 12) printf("00:");
	else printf("%02lld:", t / 3600ll);
	t %= 3600;
	printf("%02lld:", t / 60ll);
	t %= 60;
	printf("%02lld\n", t);
	return 0;
}