#include <bits/stdc++.h>
#define ll long long
#define MAXN 100010
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define mii map<int, int>
#define umii unordered_map<int, int>
using namespace std;

int S, K, s[MAXN], a[MAXN];
mii num;
ll ans;

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> S >> K;
	for (int i=0; i<S; i++) {
		cin >> s[i];
		num[s[i]] = i;
	}
	int prev = -1;
	for (int i=0; i<K; i++) {
		cin >> a[i];
		if (~prev) ans += abs(num[prev] - num[a[i]]);
		else ans++;
		prev = a[i];
 	}
 	cout << ans << endl;
	return 0;
}