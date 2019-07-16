#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define mii map<int, int>
#define umii unordered_map<int, int>
using namespace std;

ll Dist (int x1, int y1, int x2, int y2) {
  return abs(x1 - x2) + abs(y1 - y2);
}

int main () {
	int x0, y0, N, x, y;
	scanf("%d %d %d", &x0, &y0, &N);
	int maxx = 0;
	for (int i=1; i<=N; i++) {
		scanf("%d %d", &x, &y);
		if (Dist(x, y, x0, y0) > maxx) maxx = Dist(x, y, x0, y0); 
	}
	printf("%d\n", maxx * maxx << 1);
	return 0;
}