#include <bits/stdc++.h>
#define ll long long 
#define INF 0x3f3f3f3f
#define vii vector<int> 
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
using namespace std;

const int MAXN = 50001;
vii vec[MAXN];
ll N, x, y, arr[MAXN], sum[MAXN], len, cnt;

inline void DFS (int par, int root) {
      arr[root] = 0; 
      sum[root] = 1;
      for (int i=0; i<vec[root].size(); i++) {
        int e = vec[root][i];
        if (e ^ par) {
        DFS(root, e);
        if (len < arr[root] + 1 + arr[e]) {
          len = arr[root] + 1 + arr[e];
          cnt = sum[root] * sum[e];
        }
        else if (len == arr[root] + 1 + arr[e]) cnt += sum[root] * sum[e];
          
        if (arr[root] < 1 + arr[e]) {
          arr[root] = arr[e] + 1;
          sum[root] = sum[e];
        }
        else if (arr[root] == arr[e] + 1) sum[root] += sum[e];
        }
      }
    }
    
int main () {
  scanf("%lld", &N);
  for (int i=1; i<N; i++) {
    scanf("%lld %lld", &x, &y);
    vec[x].pb(y);
    vec[y].pb(x);
  }
  DFS(0, 1);
  return !printf("%lld\n", cnt);
}
