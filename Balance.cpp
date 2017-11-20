#include <bits/stdc++.h>
#define ll long long
#define MAXN 100010
#define INF 0x3f3f3f3f
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define mii map<int, int>
#define umii unordered_map<int, int>
using namespace std;
 
bool ArePair(char opening,char closing) {
  if (opening == '(' && closing == ')') return 1;
  return 0;
}

bool AreParanthesesBalanced(string exp) {
  stack<char> S;
  for (int i=0; i<exp.length(); i++) {
    if (exp[i] == '(') S.push(exp[i]);
    else if (exp[i] == ')') {
      if (S.empty() || !ArePair(S.top(), exp[i])) return 0;
      else S.pop();
    }
  }
  return S.empty();
}
 
int countMinReversals(string expr) {
    int len = expr.length();
    if (len & 1) return -1;
    stack<char> s;
    for (int i=0; i<len; i++) {
        if (expr[i] == ')' && !s.empty()) {
            if (s.top() == '(') s.pop();
            else s.push(expr[i]);
        }
        else s.push(expr[i]);
    }
    int len1 = s.size();
    int n = 0;
    while (!s.empty() && s.top() == '(') {
        s.pop();
        n++;
    }
    return ((len1 >> 1) + (n & 1));
}
 
int main() {
   string expr;
   cin >> expr;
   if (countMinReversals(expr) == 1 || AreParanthesesBalanced(expr)) cout << "YES" << endl;
   else cout << "NO" << endl;
   return 0;
}