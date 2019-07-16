#include <bits/stdc++.h>
#define ll long long
using namespace std;

int N;

int main () {
  cin.sync_with_stdio(0);
  cin.tie(0);
  for (int i=0; i<5; i++) {
  	int idx = 0, idx1 = 0;
  	cin >> N;
  	assert(N > 0);
  	while (((N >> idx) & 1) == 0) idx++; // # of rightmost bits
  	while ((N >> idx) & 1) { // # of left consecutive 1s of rightmost consecutive 0s
  		idx++;
  		idx1++;
  	}
  	N &= ~((1ll << idx) - 1); // Unset lower bits
  	N |= (1ll << idx); // Set leading 1
  	N |= (1ll << (idx1 - 1)) - 1; // Set trailing 1s
  	cout << N << "\n";
  }
  return 0;
}