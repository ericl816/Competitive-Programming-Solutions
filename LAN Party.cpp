#include <bits/stdc++.h>
#define min(x, y) ((x) < (y) ? (x) : (y))
#define p pop()
#define t top()
using namespace std;

const int MAXN = 355;
int R, C, M, u, v, arr[MAXN];
bool grid[MAXN][MAXN][MAXN];
stack<int> st; 

void recur (int a, int b, int c) {
  if (grid[a][b][c]) {
    grid[a][b][c] = 0;
    recur(a, b, c + 1);
    recur(a - 1, b, c + 1);
    recur(a, b - 1, c + 1);
    recur(a - 1, b - 1, c + 1);
    arr[c]--;
    if (!arr[c]) {
      while(c <= st.t) st.p;
    }
  }
}

int main () {
  scanf("%d %d \n%d", &R, &C, &M);
  st.push(0);
  for (int i=0; i<=min(R, C); ) {
    for (int j=1; j<=R - i; j++) {
      for (int k=1; k<=C - i; k++) {
        arr[i + 1]++; 
        grid[j][k][i + 1] = 1;
      }
    }
    st.push(i++);
  }
  for (int i=0; i<M; i++) {
    scanf("%d %d", &u, &v);
    recur(u, v, 1);
    printf("%d\n", st.t);
    }
}
