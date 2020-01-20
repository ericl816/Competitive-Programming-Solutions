#include <bits/stdc++.h>
#define ll long long
#define MAXN 100010
#define vi vector<int>
#define pb push_back
#define mii map<int, int>
#define umii unordered_map<int, int>
#define msi map<string, int>
#define umsi unordered_map<string, int>
using namespace std;

int T, N;
vi cnt[MAXN];
string s, k;
umsi arr;

int main () {
  cin.sync_with_stdio(0);
  cin.tie(0);
	cin >> T;
	for (int i=0; i<T; i++) {
		cin >> s;
		arr[s] = i;
	}
  cin >> N;
	for (int i=0; i<N; i++) {
		cin >> k;
		cnt[arr[k]].pb(i + 1);
	}
	for (int i=0; i<T; i++) {
		for (int j=0; j<cnt[i].size(); j++) 
			cout << cnt[i][j] << "\n";
	}
	return 0;
}