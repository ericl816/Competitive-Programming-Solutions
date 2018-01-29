#include <bits/stdc++.h>
#define ll long long
#define MAXN 100010
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

int N, D, x[MAXN], start1 = INF, turned1 = -INF, finished1 = INF, start2 = -INF, turned2 = INF, finished2 = -INF;

// Basically there are 3 points we need to only consider: the start point, the turning point, and the end point

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> D;
	for (int i=1; i<=N; i++) cin >> x[i];
	for (int i=0, a, b; i<D; i++) {
		cin >> a >> b;
		a = x[a]; b = x[b];
		if (a < b) {
			start1 = min(start1, a);
			turned1 = max(turned1, b);
			finished2 = max(finished2, b);
			turned2 = min(turned2, a);
		}
		else if (b <= a) {
			finished1 = min(finished1, b);
			turned1 = max(turned1, a);
			start2 = max(start2, a);
			turned2 = min(turned2, b);
		}
	}
	if (start1 == INF) start1 = turned1;
	if (finished1 == INF) finished1 = turned1;
	if (start2 == -INF) start2 = turned2;
	if (finished2 == -INF) finished2 = turned2;
	cout << (min(abs(turned2 * 2 - (start2 + finished2)), turned1 * 2 - (start1 + finished1))) << endl;
	return 0;
}