#include <bits/stdc++.h>
#define ll long long
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

int N, X, Y, minnx = INF, minny = INF, maxxx = -INF, maxxy = -INF, ans;

int main () {
	scanf("%d", &N);
	for (int i=0; i<N; i++) {
		scanf("%d %d", &X, &Y);
		minnx = min(minnx, X);
		maxxx = max(maxxx, X);
		minny = min(minny, Y);
		maxxy = max(maxxy, Y);
	}
	ans = max(abs(minnx - maxxx), abs(minny - maxxy));
	printf("%d\n", ans * ans);
	return 0;
}