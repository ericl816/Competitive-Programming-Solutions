#include <bits/stdc++.h>
#define ll long long
using namespace std;

int EQUIPPED, ITEM;

int main () {
  cin.sync_with_stdio(0);
  cin.tie(0);
  for (int i=0; i<5; i++) {
    cin >> EQUIPPED >> ITEM;
    assert(EQUIPPED >= 0 && EQUIPPED <= 255 && ITEM >= 0 && ITEM <= 7);
    cout << ((EQUIPPED & (1 << ITEM)) > 0) << "\n";
  }
  return 0;
}