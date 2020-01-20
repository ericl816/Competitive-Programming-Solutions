#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define MAXN 1000010
#define SEED 31
#define MOD 1000000007
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define mii map<int, int>
using namespace std;

string s;

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	getline(cin, s);
	int idx = s.find(":");
	string temp1 = s.substr(0, idx);
	string temp2 = s.substr(idx + 1);
	int temp3 = atoi(temp1.c_str());
	int temp4 = atoi(temp2.c_str());
	int currtime = temp3 * 60 + temp4;
	for (int i=1; i<=12; i++) {
		if ((currtime >= 420 && currtime < 600) || (currtime >= 900 && currtime < 1140)) currtime += 20;
		else currtime += 10;
	}
	if (currtime >= 1440) currtime -= 1440;
	int hours = currtime / 60;
	int minutes = currtime % 60;
	if (hours < 10) cout << "0";
	cout << hours << ":";
	if (minutes < 10) cout << "0";
	cout << minutes << endl;
	return 0;
}