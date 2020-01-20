#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define ull unsigned long long
#define MAXN 310
#define INF 0x3f3f3f3f
#define min(a, b) (a) < (b) ? (a) : (b)
#define max(a, b) (a) < (b) ? (b) : (a)
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define mii map<int, int>
#define umii unordered_map<int, int>
#ifdef DEBUG
  #define D(x...) printf(x)
#else
  #define D(x...)
#endif
using namespace std;

int N, Q, C, X, Y, Z, L, X1, Y1, Z1;
ll ans;
char op;

struct BIT {
private:
  int N;
  ll tree[MAXN][MAXN][MAXN];

public:
  BIT (int N) : N(N) { }

  inline void Update (int x, int y, int z, int val) {
    for (int i=x; i<=N; i += i & -i) {
      for (int j=y; j<=N; j += j & -j) {
        for (int k=z; k<=N; k += k & -k) {
          tree[i][j][k] += val;
        }
      }
    }
  }

  inline ll Query (int x, int y, int z) {
    ll sum = 0;
    for (int i=x; i; i -= i & -i) {
      for (int j=y; j; j -= j & -j) {
        for (int k=z; k; k -= k & -k) {
          sum += tree[i][j][k];
        }
      }
    }
    return sum;
  }

  inline ll Query (int x1, int y1, int z1, int x2, int y2, int z2) {
    return Query(x2, y2, z2) - Query(x1, y2, z2) - Query(x2, y1, z2) - Query(x2, y2, z1) + Query(x1, y1, z2) + Query(x2, y1, z1) + Query(x1, y2, z1) - Query(x1, y1, z1);
  }
};

BIT tree(MAXN);

int main (int argc, char const *argv[]) {
  #ifdef NOT_DMOJ
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif // NOT_DMOJ
  cin.sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> N >> Q;
  while (Q--) {
    cin >> op >> X >> Y >> Z;
    if (op == 'C') {
      cin >> L;
      tree.Update(X, Y, Z, L - tree.Query(X - 1, Y - 1, Z - 1, X, Y, Z));
    }
    else {
      cin >> X1 >> Y1 >> Z1;
      ans += tree.Query(X - 1, Y - 1, Z - 1, X1, Y1, Z1);
    }
  }
  cout << ans << "\n";
  return 0;
}

/* 
 * Look for:
 * the exact constraints (multiple sets are too slow for n=10^6 :( ) 
 * special cases (n=1?)
 * overflow (ll vs int?)
 * array bounds
 */