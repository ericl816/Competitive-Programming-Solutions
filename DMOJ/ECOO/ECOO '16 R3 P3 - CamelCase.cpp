#include <algorithm>
#include <vector>
#include <map>
#include <string.h>
#include <iostream>
#include <cstring>
#include <set>
#define ll long long
#define MAXN 2010
#define vi vector<int>
using namespace std;

int test_cases = 10, N;
string s;
int DP[MAXN];
set<string> dict;

int main () {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  for (int i=0; i<N; i++) {
    cin >> s;
    dict.insert(s);
  }
  while (test_cases--) {
    cin >> s;
    DP[0] = -1;
    for (int i=1; i<=s.length(); i++) DP[i] = MAXN;
    for (int i=0; i<s.length(); i++) {
      for (int j=0; j+i<=s.length(); j++) {
        if (dict.find(s.substr(i, j)) != dict.end()) DP[i + j] = min(DP[i + j], DP[i] + 1);
      }
    }
    cout << DP[s.length()] << "\n";
  }
  return 0;
}