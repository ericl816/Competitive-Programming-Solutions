#include <bits/stdc++.h>
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
#define mlli map<ll, int>
#define umlli unordered_map<ll, int>
#define SIZEOF(arr) sizeof(arr) / sizeof(arr[0])
using namespace std;
  
// Use BIT to count the number of inversions required
// This question involves finding the longest increasing "subarray"
// ** Subarrays are contiguous, whereas subsequences are not **
struct BIT {
private:
  int N;
  vi tree;
  
public:
  BIT(int N) : N(N), tree(N + 1) { }
  
  void Update (int idx, int val) {
    for (; idx<=MAXN; idx += idx & -idx) tree[idx] += val;
  }
  
  ll Query (int idx) {
    ll sum = 0;
    for (; idx; idx -= idx & -idx) sum += tree[idx];
    return sum;
  }
  
  ll Query (int a, int b) {
    return Query(b) - Query(a - 1);
  }
};
  
int N, ord[MAXN], DP[MAXN], num, X, idx, idx1; //num = N - X, where X is the len of longest subarray
ll arr[MAXN];
mlli sour; //Stores the value and the idx
char op = 'F', op1 = 'B';
//bool front, back, invert, flag;
BIT tree(MAXN);
  
int main () {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  for (int i=1; i<=N; i++) {
    cin >> arr[i];
    sour[arr[i]] = i;
  }
  for (int i=1; i<=N; i++) {
    cin >> ord[i];
    arr[sour[ord[i]]] = i; //Update the given indices
  }
  for (int i=1; i<=N; i++) sour[arr[i]] = i;
    
  // Do DP to find the longest subarray of the second sequence
  /*
  for (int i=1; i<=N; i++) {
    for (int j=0; j<i; j++) {
      if (ord[j] < ord[i]) {
        DP[i] = max(DP[i], DP[j] + 1);
        flag = 1;
      }
      if (DP[i] > X) X = DP[i];
    }
  }
  */
  sour[0] = 0;
  pii ind = pii(-1, 0);
  pii temp = pii(0, 1);
  for (int i=1; i<=N; i++) {
    if (sour[i - 1] < sour[i]) temp.f++;
    else {
      ind = max(ind, temp);
      temp = mp(1, i);
    }
  }
  ind = max(ind, temp);
  X = ind.f;
  num = N - X;
  cout << num << "\n";
  for (int i=ind.s - 1; i>0; i--) {
    idx = sour[i] + tree.Query(sour[i]);
    cout << op << " " << idx << "\n";
    tree.Update(1, 1);
    tree.Update(sour[i], -1);
    //front = 1;
  }
  for (int i=X + ind.s; i<=N; i++) {
    idx1 = sour[i] + tree.Query(sour[i]);
    cout << op1 << " " << idx1 << "\n";
    tree.Update(sour[i] + 1, -1);
    tree.Update(N + 1, 1); 
    //back = 1;
  }
  return 0;
}