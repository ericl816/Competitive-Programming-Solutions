#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define pb push_back
#define lb lower_bound
#define MAXN 100010
using namespace std;

int n, arr[MAXN], p[MAXN], vis[MAXN];
vector<vi> ans;

int main() {
	scanf("%d", &n);
	for (int i=0; i<n; i++) {
		scanf("%d", &arr[i]);
		p[i] = arr[i];
	}
	sort(p, p + n);
	for (int i=0; i<n; i++) arr[i] = lb(p, p + n, arr[i]) - p;
	for (int i=0; i<n; i++)
		if (!vis[i]) {
			int idx = i;
			vi vec;
			while (!vis[idx]) {
				vis[idx] = 1;
				vec.pb(idx + 1);
				idx = arr[idx];
			}
			ans.pb(vec);
		}
	printf("%d\n", ans.size());
	for (auto next : ans) {
		printf("%d", next.size());
		for (auto i : next) printf(" %d", i);
		printf("\n");
	}
	return 0;
}
