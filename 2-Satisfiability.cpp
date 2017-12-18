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

int B;
long double ans1, ans2;

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> B;
	ans1 = B / 2.0;
	ans2 = 1.0 * B - B / 2.0;
	cout << "$" << setprecision(2) << fixed << ans1 << " $" << setprecision(2) << fixed << ans2 << endl;
	return 0;
}