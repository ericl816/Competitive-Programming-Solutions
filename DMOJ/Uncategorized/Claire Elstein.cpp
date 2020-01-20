#include <bits/stdc++.h>
#define ll long long
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define MAXN 100010
#define MOD 1000000007
#define INF 0x3f3f3f3f
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

ll N, M, i, j, sum[MAXN], num[MAXN], degreeout[MAXN], ans;
bool flag[MAXN];
vi edge[MAXN];

ll MulMod(ll n) {
  return n % MOD;
}

void Compute () {
  memset(flag, 1, sizeof(flag));
  for (int k=1; k<=N; k++) {
    if (!edge[k].empty()) {
      flag[k] = 0;
      for (size_t i=0; i<edge[k].size(); i++) {
        sum[edge[k][i]] = MulMod(MulMod(sum[edge[k][i]]) + MulMod(sum[k]));
        num[edge[k][i]] = MulMod(MulMod(num[edge[k][i]]) + MulMod(num[k]) + MulMod(sum[k]));
      }
    }
    if (flag[k]) ans = MulMod(ans + num[k]);
  }
}

int main () {
  scan(N); scan(M);
  for (int a=1; a<=N; a++) sum[a] = 1;
  for (int a=1; a<=M; a++) {
    scan(i); scan(j);
    sum[j] = 0;
    degreeout[j]++;
    edge[i].pb(j);
  }
  Compute();
  printf("%lld\n", MulMod(ans));
  return 0;
}