#include <bits/stdc++.h>
#define ll long long
#define MAXN 100000
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define EPS 1e-6
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define mii map<int, int>
#define umii unordered_map<int, int>
using namespace std;

int Q, Y, Z;
double lo, hi = MAXN;

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> Q;
	for (int i=0; i<Q; i++) {
		cin >> Y >> Z;
		lo = 0;
		hi = MAXN;
		while (hi - lo >= EPS) {
			double mid = (lo + hi) / 2.0;
			double res = 1;
			for (int j=0; j<Y; j++) {
				res = pow(mid, res);
				if (res > Z) break;
			}
			if (res > Z) hi = mid;
			else lo = mid;
		}
		cout << setprecision(10) << fixed << lo << "\n";
	}
	return 0;
}