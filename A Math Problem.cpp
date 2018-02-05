#include <bits/stdc++.h>
#define ll long long
#define MAXM 2010
#define MAXN 10000010
#define INF 0x3f3f3f3f
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

int K, P, X, M;
double f, minn = INF, res;

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> K >> P >> X;
	for (int i=1; i<=10000; i++) {
		res = 1.0 * (i * X + 1.0 * (K * P) / i);
		if (res < minn) {
			minn = res;
			M = i;
		}
	}
	cout << setprecision(3) << fixed;
	cout << minn << endl;
	return 0;	
}