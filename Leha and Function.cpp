#include <bits/stdc++.h>
#define ll long long
#define MAXN 200010
#define pii pair<int, int>
#define f first
#define s second

using namespace std;

int n, arr[MAXN], ans[MAXN];
pii p[MAXN];

int main () {
	cin >> n;
	for (int i=0; i<n; i++) 
		cin >> arr[i];
	for (int i=0; i<n; i++) {	
		cin >> p[i].f;
		p[i].s = i;
	}
	sort(arr, arr + n);
	sort(p, p + n);
	reverse(arr, arr + n);
	for (int i=0; i<n; i++) ans[p[i].s] = arr[i];
	for (int i=0; i<n; i++) cout << ans[i] << " ";
  return 0;	
}
