#include <bits/stdc++.h>
#define ll long long
#define MAXN 10000010
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

char ch[MAXN];
ll N, ans;

inline bool Check (ll N) {
  return to_string(N).find('0') == -1;
}

ll fun () {
  for (ll i=N + 1; i<=MAXN; i++) if (Check(i)) return i;
}

int main () {
  scanf("%d", &N);
  printf("%lld\n", fun());
  return 0; 
}