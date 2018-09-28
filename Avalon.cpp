#include <bits/stdc++.h>
#define ll long long
#define MAXN 1010
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

int G, e, p;
double ans = 1;

int main () {
	cin >> G;
	for (int i=0; i<G; i++) {
	  	cin >> e >> p;
	  	if (e == p) return 0 * printf("%.10lf\n", 0);
	  	else ans *= ((double) (p - e) / p);
	}
	printf("%.10lf\n", ans);
	return 0;
}