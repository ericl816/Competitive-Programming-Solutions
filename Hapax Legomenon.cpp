#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define si set<int>
#define ss set<string>
#define umsi unordered_map<string, int>
using namespace std;

int N, cnt;
string s;
umsi arr;

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i=0; i<N; i++) {
		cin >> s;
		arr[s]++;
	}
	umsi::iterator it = arr.begin();
	for (it; it != arr.end(); it++) if (it->s == 1) cnt++;
	cout << cnt << "\n";
	return 0;
}
