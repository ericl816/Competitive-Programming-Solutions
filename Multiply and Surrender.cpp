#include<bits/stdc++.h>
#define ll long long 
using namespace std;
int N;
long double A, ans = 0; 
int main () {
  cin >> N;
  for (int i=0; i<N; i++) {
  cin >> A;
    ans += pow((log(2) / log(A)), -1);
  }
  cout << (ll) floor(ans) + 1 << "\n";
}
