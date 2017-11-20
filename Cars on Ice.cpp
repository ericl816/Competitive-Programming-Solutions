#include <bits/stdc++.h>
#define ll long long
#define MAXN 2010
#define INF 0x3f3f3f3f
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define mii map<int, int>
#define umii unordered_map<int, int>
using namespace std;

int N, M;
char grid[MAXN][MAXN];

void Check (int r, int c) {
  if (grid[r][c] == 'N') {
    for (int i=r - 1; i>=0; i--) 
      if (grid[i][c] ^ '.') 
        Check(i, c);
  }
  else if (grid[r][c] == 'S') {
    for (int i=r + 1; i<N; i++) 
      if (grid[i][c] ^ '.') 
        Check(i, c);
  }
  else if (grid[r][c] == 'E') {
    for (int i=c + 1; i<M; i++)  
      if (grid[r][i] ^ '.') 
        Check(r, i);
  }
  else if (grid[r][c] == 'W') {
    for (int i=c - 1; i>=0; i--) 
      if (grid[r][i] ^ '.') 
        Check(r, i);
  }
    grid[r][c] = '.';
    printf("(%d,%d)\n", r, c);
}

int main() {
    scanf("%d %d", &N, &M);
    for (int i=0; i<N; i++) scanf("%s", grid[i]);
    for (int i=0; i<N; i++) 
      for (int j=0; j<M; j++)
        if (grid[i][j] ^ '.')
          Check(i, j);
}