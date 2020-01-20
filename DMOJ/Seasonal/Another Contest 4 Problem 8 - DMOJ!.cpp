#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll f(string s) {
  ll d = 0;
  ll m = 0;
  ll o = 0;
  ll j = 0;
  for (int i = 0; i < s.size(); i++) {
    if(s[i] == 'D') d++;
    if(s[i] == 'M') m += d;
    if(s[i] == 'O') o += m;
    if(s[i] == 'J') j += o;
  }
  return j;
}