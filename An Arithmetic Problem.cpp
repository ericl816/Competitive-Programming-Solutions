#include <bits/stdc++.h>
#define ll long long
#define MAXN 55
#define INF 0x3f3f3f3f
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

string s, temp1, temp3, temp5;
int idx, temp2, idx1, temp4, temp6;

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	getline(cin, s);
	idx = s.find(" + ");
	temp1 = s.substr(0, idx);
	temp2 = atoi(temp1.c_str());
	idx1 = s.find(" = ");
	temp3 = s.substr(idx + 3, idx1);
	temp4 = atoi(temp3.c_str());
	temp5 = s.substr(idx1 + 3);
	temp6 = atoi(temp5.c_str());
	if (temp2 + temp4 == temp6) cout << "True" << endl;
	else cout << "False" << endl;
	return 0;	
}