#include <bits/stdc++.h>
#define ll long long
#define s second
#define mii map<int, int>
using namespace std;

int N, num;
ll ans;
mii tree;

int main() {
   scanf("%d", &N);
   for (int i=0; i<N; i++) {
      scanf("%d", &num);
      int depth = 0;
      auto it = tree.lower_bound(num);
      if (it != tree.end()) depth = max(depth, it->s + 1);
      if (it != tree.begin()) depth = max(depth, (--it)->s + 1);
      tree[num] = depth;
      ans += depth;
      printf("%lld\n", ans);
   }
}