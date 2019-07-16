#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define ull unsigned long long
#define MAXN 100010
#define INF 0x3f3f3f3f
#define min(a, b) (a) < (b) ? (a) : (b)
#define max(a, b) (a) < (b) ? (b) : (a)
#define vi vector<int>
#define vll vector<ll>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define mii map<int, int>
#define umii unordered_map<int, int>
#define DEBUG 1
#ifdef DEBUG
  #define D(x...) printf(x)
#else
  #define D(x...)
#endif
using namespace std;

inline int GCD (int a, int b) { return b == 0 ? a : GCD(b, a % b); }
inline int LCM (int a, int b) { return a * b / GCD(a, b); }
inline ll PowMod (ll a, ll b, ll MOD) { ll val = 1; while (b) { if (b & 1) val = (val * a) % MOD; a = (a * a) % MOD; b >>= 1; } return val; }

int N, v, minn, maxx;
string op, s;
int par[MAXN];
int DP[2][2][MAXN];
bool AC[MAXN], que[MAXN], vis[MAXN];
vi adj[MAXN];

inline void DFS (int node, int prev) {
  if (vis[node]) return;
  vis[node] = 1;
  DP[0][0][node] = DP[1][0][node] = 1;
  for (auto i : adj[node]) {
    if (i == prev) continue;
    DFS(i, node);
    if (que[i]) {
      DP[0][0][node] += min(DP[0][0][i], DP[0][1][i]);
      DP[0][1][node] += min(DP[0][0][i], DP[0][1][i]);
      DP[1][0][node] += max(DP[1][0][i], DP[1][1][i]);
      DP[1][1][node] += max(DP[1][0][i], DP[1][1][i]);
    }
    else {
      DP[0][AC[node]][node] += DP[0][AC[node] ^ AC[i] ^ 1][i];
      DP[0][AC[node] ^ 1][node] += DP[0][AC[node] ^ AC[i]][i];
      DP[1][AC[node]][node] += DP[1][AC[node] ^ AC[i] ^ 1][i];
      DP[1][AC[node] ^ 1][node] += DP[1][AC[node] ^ AC[i]][i];
    }
  }
}

int main (int argc, char const *argv[]) {
  #ifdef NOT_DMOJ
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif // NOT_DMOJ
  cin.sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> N;
  for (int i=1; i<=N; i++) {
    cin >> op;
    if (op == "C") cin >> s;
    else {
      cin >> v >> s;
      par[i] = v;
      adj[v].pb(i);
    }
    AC[i] = s == "AC";
    que[i] = s == "?";
  }
  for (int i=1; i<=N; i++) {
    if (!par[i]) {
      DFS(i, -1);
      if (que[i]) {
        minn += min(DP[0][0][i], DP[0][1][i]);
        maxx += max(DP[1][0][i], DP[1][1][i]);
      }
      else {
        minn += DP[0][AC[i]][i];
        maxx += DP[1][AC[i]][i];
      }
    }
  }
  cout << minn << " " << maxx << "\n";
  return 0;
}

/* 
 * Look for:
 * the exact constraints (multiple sets are too slow for n=10^6 :( ) 
 * special cases (n=1?)
 * overflow (ll vs int?)
 * array bounds
 */