#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f
#define MAXN 28
#define vi vector<int>
#define pb push_back
using namespace std;

int n, m;

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	if (n >= 30) cout << m;
	else cout << (m % (1 << n)) << endl;
}
