#include <bits/stdc++.h>
#define ll long long
#define MAXM 110
#define MAXN 10010
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

int n, m, price[MAXM];
vi primes, objects;
bool prime[MAXN], bought[MAXN];

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i=0; i<m; i++) cin >> price[i];
	memset(prime, 1, sizeof(prime));
	prime[0] = prime[1] = 0;
	for (int i=2; i<=n; i++) if (prime[i]) for (int j=i + i; j<=n; j+=i) prime[j] = 0; // Not prime
	for (int i=0; i<=n; i++) if (prime[i]) primes.pb(i);
	objects.pb(0);
	for (int i=0; i<m; i++) {
		memset(bought, 0, sizeof(bought));
		vi temp;
		temp.reserve(MAXN);
		for (int &next : objects) {
			for (int &next1 : primes) {
				if (n < next + price[i] * next1) break;
				if (!bought[next + price[i] * next1]) {
					bought[next + price[i] * next1] = 1;
					temp.pb(next + price[i] * next1);
				}
			}
		}
		objects = temp;
	}
	for (int &next : objects) 
		if (prime[next]) {
			cout << "its primetime" << endl;
			return 0;
	  }
	cout << "not primetime" << endl;
	return 0;
}