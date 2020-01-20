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
ll sum;
bool prime[MAXN], bought[MAXN];

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i=0; i<m; i++) cin >> price[i];
	for (int i=0; i<m; i++) sum += price[i];
	if (sum << 1 > n) cout << "not primetime" << endl;
	else cout << "its primetime" << endl;
	return 0;
}