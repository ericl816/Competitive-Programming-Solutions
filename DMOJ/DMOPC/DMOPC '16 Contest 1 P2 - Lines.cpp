#include <bits/stdc++.h>
#define ll long long
#define MAXN 100010
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define umii unordered_map<int, int>
#define mii map<int, int>
#define umiumii unordered_map<int, umii>
#define mimii map<int, mii>
#define si set<int>
#define umisi unordered_map<int, si>
#define misi map<int, si>
using namespace std;

int N, m[MAXN], b[MAXN];
ll numpoi;
bool flag;
mimii lines;

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i=0; i<N; i++) {
		cin >> m[i] >> b[i];
		lines[m[i]][b[i]]++;
		if (lines[m[i]][b[i]] > 1) {
			flag = 1;
			cout << "Infinity" << "\n";
			return 0;
			break;
		}
	}
	for (int i=0; i<N; i++) numpoi += N - lines[m[i]].size();
	cout << ((ll) numpoi >> 1) << "\n";
	return 0;
}