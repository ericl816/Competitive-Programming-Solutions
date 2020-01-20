#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXN 110
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

int N;
int grid[MAXN][MAXN], arr[MAXN][MAXN];

void RotateCW () {
	for (int i=0; i<N; i++) for (int j=0; j<N; j++) arr[i][j] = grid[j][N - i - 1];
	for (int i=0; i<N; i++) for (int j=0; j<N; j++) grid[i][j] = arr[i][j];
}

int main () {
  scan(N);
  for (int i=0; i<N; i++) for (int j=0; j<N; j++) scan(grid[i][j]);
  while (grid[0][0] >= grid[1][0] || grid[0][0] >= grid[0][1]) RotateCW();
  for (int i=0; i<N; i++) {
    for (int j=0; j<N; j++) printf("%d ", grid[i][j]);
  	printf("\n");
  }
  return 0;
}