#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define ll long long
#define MAXN 355
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define min(x, y) ((x) < (y) ? (x) : (y))
using namespace std;

/* Solution uses a histogram to keep track of the available square sizes
 * Overall Time Complexity is O(N^3). See DFS method down below
 */

int R, C, M, u, v;
int hist[MAXN];
bool grid[MAXN][MAXN][MAXN];
stack<int> st; 

// Time Complexity: O(N^3)
inline void DFS (int c, int a, int b) {
  if (grid[c][a][b]) {
    grid[c][a][b] = 0;
    DFS(c + 1, a, b);
    DFS(c + 1, a - 1, b);
    DFS(c + 1, a, b - 1);
    DFS(c + 1, a - 1, b - 1);
    if (!--hist[c]) while(c <= st.top()) st.pop();
  }
}

int main () {
  scan(R); scan(C); scan(M);
  st.push(0);
  for (int i=0; i<=min(R, C); ) {
    for (int j=1; j + i<=R; j++) {
      for (int k=1; k + i<=C; k++) {
        hist[i + 1]++;
        grid[i + 1][j][k] = 1;
      }
    }
    st.push(i++);
  }
  for (int i=0; i<M; i++) {
    scan(u); scan(v);
    DFS(1, u, v);
    printf("%d\n", st.top());
  }
  return 0;
}