#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
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

string s, s1, s2;
int idx, cnt;
bool flag;
vector<char> vec;
char ch;

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> s;
	if (s.size() > 1 && s[0] == '0') {
	  cout << "Invalid" << endl;
	  return 0;
	}
	if (s.size() == 1 && s == "0") {
	  cout << "Valid" << endl;
	  return 0;
	}
	for (int i=0; i<s.size(); i++) {
		flag = 0;
		if (s[i] != '0') {
			ch = s[i];
			idx = i;
			vec.pb(ch);
		}
		if (idx >= 0 && (int) ch - '0' <= s.size() && (int) ch - '0' >= 1) s1 = s.substr(idx + 1, (int) ch - '0');
		if (s1.size() == 1 && s[idx + 2] == '0') flag = 1;
		if (s1.size() > 0) {
			for (int j=0; j<s1.size(); j++) {
				if (s1[j] != '0') {
					flag = 1;
					break;
				}
			}
		}
		if (!flag && s1 != s2 && s1.size() == (int) ch - '0') {
			cnt++;
			s2 = s1;
		}
	}
	cout << (cnt == (int) vec[0] - '0' ? "Valid" : "Invalid") << "\n";
	return 0;
}