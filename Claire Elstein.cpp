#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ull unsigned long long
#define e empty()
#define pb push_back
using namespace std;

const int MAXN = 100010, MOD = 1e9 + 7;
ull N, M, i, j, sum[MAXN], num[MAXN], degreeout[MAXN], ans = 0;
bool flag[MAXN];
vector< vector <int> > edge = vector< vector <int> >(MAXN);

ull MulMod(ull n) {
  return n % MOD;
}

void Compute () {
  memset(flag, 1, sizeof(flag));
  for (int k=0; k<N; k++) {
    if (!edge[k].e) {
      flag[k] = 0;
      for (int i=0; i<edge[k].size(); i++) {
        sum[edge[k][i]] = MulMod(MulMod(sum[edge[k][i]]) + MulMod(sum[k]));
        num[edge[k][i]] = MulMod(MulMod(num[edge[k][i]]) + MulMod(num[k]) + MulMod(sum[k]));
            }
        }
    if (flag[k]) ans = MulMod(ans + num[k]);
    }
}

int main () {
  scan(N); scan(M);
  for (int a=0; a<N; a++) sum[a] = 1;
  for (int a=0; a<M; a++) {
    scan(i); scan(j);
    i--; j--; sum[j] = 0;
    degreeout[j]++;
    edge[i].pb(j);
  }
  Compute();
  printf("%llu\n", MulMod(ans));
  return 0;
}
