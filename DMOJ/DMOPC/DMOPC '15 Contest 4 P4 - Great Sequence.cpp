#include <bits/stdc++.h>
#define ll long long 
#define MAXN 100010
#define lb lower_bound
#define ub upper_bound
#define si set<int>
#define it si::iterator
using namespace std;

int N, K, Q, val, a, b, x, y, pre[MAXN];
si num[MAXN];

int main () {
	cin >> N >> K >> Q;
	for (int i=1; i<=N; i++) {
		cin >> pre[i];
		num[pre[i] + 1010].insert(i);
		pre[i] += pre[i - 1];
	}
	for (int i=1; i<=Q; i++) {
	    cin >> a >> b >> x >> y;
		it pos = num[a + 1010].lb(x);
		it pos1 = num[b + 1010].lb(x);
		if (pos == num[a + 1010].end() || pos1 == num[b + 1010].end() || *pos > y || *pos1 > y) cout << "No" << "\n";
		else if (pre[y] - pre[x - 1] > K) cout << "Yes" << "\n";
		else cout << "No" << "\n";
	}
}