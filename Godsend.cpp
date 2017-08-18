#include <bits/stdc++.h>
#define ll long long
#define max(a, b) (a) < (b) ? (b) : (a)
#define vi vector<int>
#define pq priority_queue<int>
#define mii map<int, int>
#define umii unordered_map<int, int>
#define pii pair<int, int>
#define mp make_pair
#define pb push_back
#define p push
#define b begin
#define e end
using namespace std;

const int MAXN = 1e6 + 10;
int n, a;
ll sum;

int main () {
scanf("%d", &n);
for (int i=1; i<=n; i++) {
  scanf("%d", &a);
  a %= 2;
  sum += a;
}
if (sum == 0) cout << "Second" << "\n";
else cout << "First" << "\n";
return 0;	
}
