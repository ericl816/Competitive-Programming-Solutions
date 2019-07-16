#if __INCLUDE_LEVEL__ == 1
//#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#else
#include __FILE__
using namespace std;
using namespace __gnu_pbds;
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> bst;

bst t;

int N, M, lastAns, x, v, a;
char C;

int main() {
    scanf("%d %d", &N, &M);
    for (int i=0; i<N; i++) {
      scanf("%d", &a);
      t.insert({a, i});
    }
    for (int i=0; i<M; i++) {
      scanf(" %c %d", &C, &x);
      x ^= lastAns;
      if (C == 'I') t.insert({x, N + i});
      else if (C == 'R') {
        bst::iterator it = t.lower_bound({x, 0});
        if (it->first == x) t.erase(it);
      }
      else if (C == 'S') {
        lastAns = t.find_by_order(x - 1)->first;
        printf("%d\n", lastAns);
      }
      else if (C == 'L') {
        bst::iterator it = t.lower_bound({x, 0});
        if (it->first == x) lastAns = t.order_of_key(*it) + 1;
        else lastAns = -1;
        printf("%d\n", lastAns);
      }
    }
    for (bst::iterator it = t.begin(); it != t.end(); it++) printf("%d ", it->first);
    return 0;
}
#endif