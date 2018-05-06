// http://codeforces.com/blog/entry/59281
#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXM 1010
#define MAXN 5010
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

int count3 (ll x) {
  int ret = 0;
  while (x % 3 == 0) {
    ret++;
    x /= 3;
  }
  return ret;
}

int n;
vector< pair <int, ll > > v;

int main () {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  v.resize(n);
  for (int i=0; i<n; i++) {
    cin >> v[i].s;
    v[i].f = -count3(v[i].s);
  }
  sort(v.begin(), v.end());
  for (int i=0; i<n; i++) printf("%lld%c", v[i].s, " \n"[i + 1 == n]);
}