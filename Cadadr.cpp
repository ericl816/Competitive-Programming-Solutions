#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
using namespace std;

string s, temp1 = "(", temp2 = ")", temp3 = " ", temp4 = "r", temp5 = "c", temp6 = "x";
int cnt;
bool flag;

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> s;
	for (int i=1; i<s.length() - 1; i++) {
		if (s[i] != 'r' && s[i] != 'c') {
			cout << (temp1 + temp5 + s[i] + temp4 + temp3);
			cnt++;
		}
	}
	cout << " x";
	for (int i=0; i<cnt; i++) cout << temp2;
	return 0;
}