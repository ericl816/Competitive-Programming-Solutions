#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f
#define MAXN 28
#define vi vector<int>
#define pb push_back
using namespace std;

int k, cnt, cnt1, ans = INF;
vector<char> vec;
string s;

int main () {
	cin >> s >> k;
	if (s.length() < k) cout << "impossible";
	else {
		for (int i=0; i<s.length(); i++) vec.pb(s[i]);
		sort(vec.begin(), vec.end());
		for (int i=1; i<=vec.size(); i++) {
		   if (vec[i] ^ vec[i - 1]) cnt++;
		   if (cnt >= k) break;
		}
		cout << k - cnt;
	}
}
