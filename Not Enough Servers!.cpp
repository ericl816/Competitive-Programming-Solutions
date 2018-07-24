#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXM 55
#define MAXN 1050000
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

int N, M, num;
int arr[MAXM];
char ch[MAXM];
bitset<MAXM> DP[MAXN];

int main () {
  scan(N); scan(M);
  for (int i=0; i<N; i++) {
    num = M;
    scanf("%s", &ch);
    for (int j=0; j<M; j++) {
      if (ch[j] == 'X') {
        arr[j] |= 1 << i;
        num--;
      }
    }
    if (num == M) for (int j=0; j<M; j++) arr[j] |= 1 << i;
  }
  for (int i=0; i<1 << N; i++) {
    for (int j=0; j<M; j++) {
      int idx = arr[j] | i;
      if (arr[j] && (!i || DP[i].count()) && (DP[i].count() + 1 < DP[idx].count() || !DP[idx].count())) {
        DP[idx] = DP[i];
        DP[idx][j] = 1;
      }
    }
  }
  int idx = (1 << N) - 1;
  printf("%d\n", DP[idx].count());
  for (int i=0; i<M; i++) if (DP[idx][i]) printf("%d ", i + 1);
  return 0;
}