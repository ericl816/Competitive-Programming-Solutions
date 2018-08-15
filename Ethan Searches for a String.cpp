#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
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
using namespace std;

// Overall Time Complexity: O(N*T)

string a, b;
int t, k, n, m;

int main () {
  // #ifdef NOT_DMOJ
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  // #endif // NOT_DMOJ
  cin.sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  for (int z=1; z<=t; z++) {
    cin >> a;
    b = "Impossible";
    for (size_t i=1; i<a.size(); i++) {
      if (a[0] == a[i]) {
        bool poss = 1;
        for (size_t j=0; j + i<a.size(); j++) {
          // Find a value for string B, such that it does not contain string A in its prefix!!!
          if (a[j] != a[i + j]) {
            poss = 0;
            break;
          }
        }
        if (!poss) {
          b = a.substr(0, i) + a;
          break;
        }
      }
    }
    cout << "Case #" << z << ": " << b << "\n";
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