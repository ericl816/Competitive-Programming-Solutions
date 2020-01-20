#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXN 100010
#define EPS 1e-6
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

int Q, Y, Z;
double lo, hi = MAXN;

int main () {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin >> Q;
	for (int i=0; i<Q; i++) {
		cin >> Y >> Z;
		hi = MAXN;
		lo = 0.0;
		double mid = 0.0;
		while (hi - lo >= EPS) {
			double res = 1.0;
			mid = static_cast<double>((lo + hi) / 2.0);
			for (int j=0; j<Y; j++) {
				res = pow(mid, res);
				if (res > Z) break;
			}
			if (res > Z) hi = mid;
			else lo = mid;
		}
		cout << fixed << setprecision(10) << lo << "\n";
	}
	return 0;
}