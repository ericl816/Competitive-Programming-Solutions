#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXN 200010
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
#define println cout << "\n";
#ifdef DEBUG
  #define D(x...) printf(x)
#else
  #define D(x...)
#endif
using namespace std;

int N, K, M;
ll ans, keys, monitors;
vector<pii> V[MAXN];

int main (int argc, char const *argv[]) {
  #ifdef NOT_DMOJ
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif // NOT_DMOJ
  cin.sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> N;
  for (int i=0; i<N; i++) {
    cin >> K >> M;
    V[K + M].pb(mp(K, M));
  }
  for (int i=0; i<MAXN; i++) {
    sort(V[i].begin(), V[i].end());
    // for (auto j : V[i]) cout << j.f << " " << j.s << "\n";
    int lo = 0, hi = V[i].size() - 1;
    keys = monitors = 0;
    while (lo <= hi) {
      if (monitors < keys) monitors += V[i][lo++].s;
      else if (monitors > keys) keys += V[i][hi--].f;
      else if (V[i][lo].s < V[i][hi].f) monitors += V[i][lo++].s;
      else keys += V[i][hi--].f;
    }
    ans = max(ans, min(monitors, keys));
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