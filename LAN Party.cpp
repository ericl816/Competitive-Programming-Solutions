#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define ull unsigned long long
#define MAXN 410
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

int R, C, M, u, v;
bool avail[MAXN][MAXN][MAXN];
bool flag;
int hist[MAXN];

inline void DFS (int r, int c, int idx = 1) {
  if (!avail[r][c][idx]) return;
  avail[r][c][idx] = 0;
  --hist[idx];
  DFS(r, c, idx + 1);
  DFS(r - 1, c, idx + 1);
  DFS(r, c - 1, idx + 1);
  DFS(r - 1, c - 1, idx + 1);
}

int main (int argc, char const *argv[]) {
  #ifdef NOT_DMOJ
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif // NOT_DMOJ
  cin.sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> R >> C >> M;
  for (int i=1; i<=R; i++) {
    for (int j=1; j<=C; j++) {
      for (int k=1; i + k - 1<=R && j + k - 1<=C; k++) {
        avail[i][j][k] = 1;
        hist[k]++;
      }
    }
  }
  for (int i=0; i<M; i++) {
    cin >> u >> v;
    DFS(u, v);
    flag = 0;
    for (int j=min(R, C); j; j--) {
      if (hist[j]) {
        cout << j << "\n";
        flag = 1;
        break;
      }
    }
    if (!flag) cout << "0\n";
  }
  return 0;
}

/* 
 * Look for:
 * the exact constraints (multiple sets are too slow for n=10^6 :( ) 
 * special cases (n=1?)
 * overflow (ll vs int?)
 * array bounds
 */