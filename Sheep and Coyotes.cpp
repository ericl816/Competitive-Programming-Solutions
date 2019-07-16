#include <bits/stdc++.h>
#define ll long long
#define MAXN 110
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

int n, e;
pair<double, double> sheep[MAXN];
bool eat[MAXN];

inline double dist (double i, int j) {
	return (sheep[j].f - i) * (sheep[j].f - i) + sheep[j].s * sheep[j].s;
}

int main () {
	scanf("%d", &n);
	
	for (int i=0; i<n; i++) scanf("%lf %lf", &sheep[i].f, &sheep[i].s);
	for (double i=0; i<=1000; i+=0.005) {
		e = 0;
		for (int j=1; j<n; j++) if (dist(i, j) < dist(i, e)) e = j;
		eat[e] = 1;
	}
	for (int i=0; i<n; i++) if (eat[i]) printf("The sheep at (%.2lf, %.2lf) might be eaten.\n", sheep[i].f, sheep[i].s);
}