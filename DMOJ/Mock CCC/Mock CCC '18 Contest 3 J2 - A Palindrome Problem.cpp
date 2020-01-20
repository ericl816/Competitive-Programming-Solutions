#include <bits/stdc++.h>
#define ll long long
#define MAXN 10
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
bool flag;
vector<string> vec;

inline bool isPalindrome (string s) {
    if (s.length() == 1) return 1;
    return (s == string(s.rbegin(), s.rend()));
}

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	getline(cin, s);
	for (int i=0; i<s.size(); i++) for (int j=i + 1; j<=s.size(); j++) if (isPalindrome(s.substr(i, j))) vec.pb(s.substr(i, j));
	for (string i : vec) {
	  for (string j : vec) {
	    if (i.length() > 0 && j.length() > 0) {
	      if (i + j == s) {
	        flag = 1;
	        goto outer;
	      }
	    }
	  }
	}
	outer: cout << (flag ? "YES" : "NO") << endl;
	return 0;
}