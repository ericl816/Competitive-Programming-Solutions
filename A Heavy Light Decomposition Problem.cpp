#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXM 100010
#define MAXN 1010
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

int n, q;
vi traversed, temp;
vi adj[MAXN];
int nodes[MAXN], freq[MAXM];
bool vis[MAXN];

void DFS (int src, int dest, vi tempVec) {
  tempVec.pb(src);
  vis[src] = 1;
  if (src == dest) for (auto it=tempVec.begin(); it!=tempVec.end(); ++it) traversed.pb(*it);
  else for (auto it=adj[src].begin(); it!=adj[src].end(); ++it) if (!vis[*it]) DFS(*it, dest, tempVec);
}

int main () {
  #ifdef NOT_DMOJ
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif // NOT_DMOJ
  cin.sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> q;
  for (int i=1; i<=n; ++i) cin >> nodes[i];
  for (int i=1, a, b; i<n; ++i) {
    cin >> a >> b;
    adj[a].pb(b);
    adj[b].pb(a);
  }
  for (int i=0, a, b, c; i<q; ++i) {
    memset(vis, 0, sizeof(vis));
    traversed.clear();
    cin >> a >> b >> c;
    DFS(b, c, temp);
    if (a == 1) {
      double average = 0, tSize = traversed.size();
      for (auto it=traversed.begin(); it!=traversed.end(); ++it) average += nodes[*it];
      ll ans = round(average / tSize);
      cout << ans << "\n";
    }
    else if (a == 2) {
      vector<double> medianVec;
      for (auto it=traversed.begin(); it!=traversed.end(); ++it) medianVec.pb(nodes[*it]);
      sort(medianVec.begin(), medianVec.end());
      int theSize = medianVec.size(), ans = 0;
      if (theSize & 1) ans = medianVec[theSize >> 1];
      else ans = round((medianVec[theSize >> 1] + medianVec[(theSize >> 1) - 1]) / 2.0);
      cout << ans << "\n";
    }
    else {
      int maxCount = 0, maxIndex;
      memset(freq, 0, sizeof(freq));
      for (auto it=traversed.begin(); it!=traversed.end(); ++it) {
        if (++freq[nodes[*it]] > maxCount) {
          maxCount++;
          maxIndex = nodes[*it];
        }
        else if (freq[nodes[*it]] == maxCount) maxIndex = min(maxIndex, nodes[*it]);
      }
      cout << maxIndex << "\n";
    }
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