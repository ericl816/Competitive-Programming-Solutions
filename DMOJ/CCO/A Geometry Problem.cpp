#include <bits/stdc++.h>
using namespace std;

int N;
pair<int, int> p[50010];
vector<int> cheese;

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> N;
  for (int i=0; i<N; i++) {
    cin >> p[i].first >> p[i].second;
    if (p[i].first && p[i].second) {
      cheese.push_back(i + 1);
    }
  }
  for (auto i : cheese) cout << i << " ";
  return 0;
}