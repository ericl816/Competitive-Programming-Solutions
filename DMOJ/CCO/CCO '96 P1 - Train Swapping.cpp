#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXN 60
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

int T, N, inv_count;
int A[MAXN];

int main () {
  #ifdef NOT_DMOJ
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif // NOT_DMOJ
  cin.sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> T;
  while (T--) {
    cin >> N;
    for (int i=0; i<N; i++) cin >> A[i];
    inv_count = 0;
    for (int i=0; i<N; i++) {
        for (int j=0; j<i; j++) {
            inv_count += A[j] > A[i];
        }
    }
    cout << "Optimal train swapping takes " << inv_count << " swaps.\n";
  }
  return 0;
}