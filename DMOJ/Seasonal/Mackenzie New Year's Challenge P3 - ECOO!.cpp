#include <bits/stdc++.h>
#define ll long long
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

int N, P;
string S, T;
vector<pair<int, string>> general, girls;
vector<string> teams;
bool flag = 1;

bool Cmp (pair<int, string> &a, pair<int, string> &b) {
  return a.f > b.f;
}

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i=0; i<N; i++) {
		cin >> S >> T >> P;
		if (T == "general") general.pb(mp(P, S));
		else if (T == "girls") girls.pb(mp(P, S));
	}
	sort(girls.begin(), girls.end(), Cmp);
	if (girls.size() >= 1) teams.pb(girls[0].s);
	for (int i=1; i<girls.size(); i++) general.pb(girls[i]);
	sort(general.begin(), general.end(), Cmp);
	for (int i=0; i<min(2, (int) general.size()); i++) teams.pb(general[i].s);
	if (teams.size() == 0) {
		cout << "No ECOO :(" << endl;
		return 0;
	}
	sort(teams.begin(), teams.end());
	for (string i : teams) cout << i << endl;
	return 0;
}