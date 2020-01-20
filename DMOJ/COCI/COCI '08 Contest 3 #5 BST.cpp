#include <bits/stdc++.h>
#define ll long long
#define mii map<int, int>
#define lb lower_bound
#define s second
#define b begin
#define e end
using namespace std;

int N, num;
ll ans;
mii tree;

int main() {
   scanf("%d", &N);
   for (int i=0; i<N; i++) {
      scanf("%d", &num);
      int depth = 0;
      auto it = tree.lb(num);
      if (it != tree.e()) depth = max(depth, it->s + 1);
      if (it != tree.b()) depth = max(depth, (--it)->s + 1);
      tree[num] = depth;
      ans += depth;
      printf("%lld\n", ans);
   }
}