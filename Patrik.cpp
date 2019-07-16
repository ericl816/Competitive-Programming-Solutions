#include <algorithm>
#include <cstdio>
#include <iostream>
#include <stack>

using namespace std;

typedef long long ll;
typedef pair <int, int> par;

stack <par> S;
ll ret = 0;
int n, h;

int main() {
   scanf("%d", &n);
   for(int i = 0; i < n; ++i) {
      scanf("%d", &h);
      par p(h, 1);
      for(; !S.empty() && S.top().first <= h; S.pop()) {
         ret += S.top().second;
         if(S.top().first == h) p.second += S.top().second;
      }
      if(!S.empty()) ++ret;
      S.push(p);
   }
   printf("%lld", ret);
}
