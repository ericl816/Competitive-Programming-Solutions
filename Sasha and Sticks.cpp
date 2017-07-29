#include <iostream>
#include <stdio.h>
using namespace std;
    
typedef long long ll;

ll n, k;

int main () {
  cin >> n >> k;
  cout << (((n / k) & 1) ? "YES" : "NO") << "\n";
}
