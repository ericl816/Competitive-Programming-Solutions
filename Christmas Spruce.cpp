#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define MAXN 1010
#define vi vector<int>
#define pb push_back
using namespace std;

int n, p[MAXN], leaves;
vi adj[MAXN];
bool flag = 1;

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i=1; i<n; i++) {
		cin >> p[i];
		adj[--p[i]].pb(i);
	}
	for (int i=0; i<n; i++) {
		if (adj[i].empty()) continue;
		leaves = 0;
		for (size_t j=0; j<adj[i].size(); j++) {
			int &next = adj[i][j];
			if (adj[next].empty()) leaves++;
		}
		flag &= (leaves >= 3);
	}
	cout << (flag ? "Yes" : "No") << endl;
}
