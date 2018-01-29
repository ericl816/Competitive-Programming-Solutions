#include <bits/stdc++.h>
#define MAXN 2010
#define INF 0x3f3f3f3f
#define ll long long
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define mii map<int, int>
#define umii unordered_map<int, int>
using namespace std;

int w, l, side, ans;

int main () {
	scanf("%d %d %d", &w, &l, &side);
	printf("%d\n", (int) round((w / side * 1.0) * (l / side * 1.0) * 1.0));
	return 0;
}