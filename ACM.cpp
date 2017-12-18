#include <bits/stdc++.h>
#define ll long long
#define MAXN 150010
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

int N, ans = INF;
int arr[MAXN][3], DP[MAXN][3];
int perm[6][3] = {{0, 1, 2}, {0, 2, 1}, {1, 0, 2}, {1, 2, 0}, {2, 1, 0}, {2, 0, 1}};

int Recur (int i, int j, int idx) {
  if (i == N) {
    if (j > 2) return 0;
    return INF;
  }
  else if (j > 2) return INF;
  int &val = DP[i][j];
  if (~val) return val;
  val = min(Recur(i + 1, j + 1, idx), Recur(i + 1, j, idx)) + arr[i][perm[idx][j]];
  return DP[i][j] = val;
}

int main () {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  for (int i=0; i<3; i++) for (int j=0; j<N; j++) cin >> arr[j][i];
  for (int i=0; i<6; i++) {
    memset(DP, -1, sizeof(DP));
    ans = min(ans, Recur(0, 0, i));
  }
  cout << ans << endl;
  return 0;
}