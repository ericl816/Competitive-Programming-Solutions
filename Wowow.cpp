#include <bits/stdc++.h>
#define MAXN 1000010
#define vi vector<int>
#define pb push_back
#define ll long long 
#define umii unordered_map<int, int>
using namespace std;

char op[MAXN];
int N, BIT[MAXN], X[MAXN], R[MAXN], K[MAXN], id[MAXN], rating[MAXN], cnt;
vi vec;
umii umap;

void Update (int idx, int val) {
  for (; idx<=MAXN; idx += idx & -idx)
    BIT[idx] += val;
}

int Query (int idx) {
  int sum = 0;
  for (; idx; idx -= idx & -idx) sum += BIT[idx];
  return sum;
}

int Search (int i) {
  int lo = 1;
  int hi = vec.size();
  while (lo <= hi) {
    int mid = (lo + hi) >> 1;
    if (Query(mid) <= cnt - K[i]) lo = mid + 1;
    else hi = mid - 1;
  } 
  return lo;
}

int main () {
  scanf("%d", &N);
  for(int i=0; i<N; i++) {
    scanf(" %c", &op[i]);
    if (op[i] == 'Q') scanf("%d", &K[i]);
    else if (op[i] == 'N' || op[i] == 'M') {
      scanf("%d %d", &X[i], &R[i]);
      vec.pb(R[i]);
    }
  }
  sort(vec.begin(), vec.end());
  // Coordinate compression
  for (int i=0; i<vec.size(); i++) umap[vec[i]] = i + 1;
  for(int i=0; i<N; i++) {
    if (op[i] == 'N') {
      cnt++;
      id[umap[R[i]]] = X[i];
      rating[X[i]] = umap[R[i]];
      Update(umap[R[i]], 1);
    }
    else if (op[i] == 'M') {
      Update(umap[R[i]], 1);
      Update(rating[X[i]], -1);
      id[umap[R[i]]] = X[i];
      rating[X[i]] = umap[R[i]];
    }
    else if (op[i] == 'Q') printf("%d\n", id[Search(i)]);
  }
  return 0;
}
