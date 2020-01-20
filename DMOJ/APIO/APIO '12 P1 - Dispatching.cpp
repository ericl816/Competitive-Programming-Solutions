#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXN 100010
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

ll N, M, B[MAXN], C[MAXN], L[MAXN], val;
priority_queue<int> pq[MAXN];

int main () {
  scan(N);
  scan(M);
  for (int i=1; i<=N; i++) {
    scan(B[i]);
    scan(C[i]);
    scan(L[i]);
    pq[i].push(C[i]);
  }
  for (int i=N; i>=1; i--) {
    val = max(val, L[i] * pq[i].size());
    if (pq[B[i]].size() < pq[i].size()) swap(pq[B[i]], pq[i]);
      while(!pq[i].empty()) {
        pq[B[i]].push(pq[i].top());
        pq[i].pop();
      }
      C[B[i]] += C[i];
      while (M < C[B[i]]) {
        C[B[i]] -= pq[B[i]].top();
        pq[B[i]].pop();
      }
  }
  printf("%lld\n", val);
}