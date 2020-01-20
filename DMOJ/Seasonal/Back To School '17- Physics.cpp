#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define ld long double
#define EPS 5e-6;
#define INF 0x3f3f3f3f
#define max(a, b) (a) < (b) ? (b) : (a)
#define min(a, b) (a) < (b) ? (a) : (b)
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define vi vector<int>
#define pb push_back
#define umii unordered_map<int, int>
#define mii ordered_map<int, int>
#define si set<int>
using namespace std;

int N, r;
ld sum, sum1;

inline ll Round(ld n) {
	if (n - floor(n) == 0.5) {
		ll temp = (ll) (floor(n));
		if (temp % 2 == 0) return temp;
		else return temp + 1;
	}
	return (ll) (round(n));
}

inline ld RoundMin(ld n) {
	return (ll) (n) % 2 == 0 ? n - 0.5 : n - 0.5 + EPS;
}

inline ld RoundMax(ld n) {
	return (ll) (n) % 2 == 0 ? n + 0.5 : n + 0.5 - EPS;
}

int main () {
	scan(N);
	for (int i=0; i<N; i++) {
		scan(r);
		sum += RoundMin(r);
		sum1 += RoundMax(r);
	}
	printf("%lld\n%lld\n", Round(sum), Round(sum1));
	return 0;
}