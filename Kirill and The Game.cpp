#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define f first
#define s second
using namespace std;

int l, r, x, y, k;

int main () {
  scanf("%d %d %d %d %d", &l, &r, &x, &y, &k);
  for (int i=x; i<=y; i++) {
  	if ((ll) i * k >= l && (ll) i * k <= r) return 0 * printf("%s\n", "YES");
  }
  printf("%s\n", "NO");
}