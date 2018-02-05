#include <bits/stdc++.h>
#define ll long long
#define MAXN 100000
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
using namespace std;

string s;
bool flag = 1;
vector<string> vec;

bool isPalindrome (string s) {
    if (s.length() == 1) return 1;
    return (s == string(s.rbegin(), s.rend()));
}

int main () {
  cin.sync_with_stdio(0);
  cin.tie(0);
  getline(cin, s);
  for (int i=0; i<s.length(); i++) {
  	for (int j=i + 1; j<=s.length() - i; j++) {
  		string next = s.substr(i, j);
  		if (isPalindrome(next)) vec.pb(next);
  	}
  }
  for (string next : vec) flag &= (next.length() & 1);
  cout << (flag ? "Odd" : "Even") << endl;
  return 0; 
}