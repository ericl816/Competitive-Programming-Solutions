#include <bits/stdc++.h>
#define ll long long
#define MAXN 200010
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

int L, G, idx, X = -1;
vi Sl, Sg;

bool Cmp (int a, int b) {
	return a > b;
}

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> L >> G;
	for (int i=0, x; i<L; i++) {
		cin >> x;
		Sl.pb(x);
	}
	for (int i=0, x; i<G; i++) {
		cin >> x;
		Sg.pb(x);
	}
	sort(Sl.begin(), Sl.end(), Cmp);
	sort(Sg.begin(), Sg.end(), Cmp);
	for (int i=0; i<G; i++) {
	  int &next = Sg[i];
		while (idx < L && Sl[idx] >= next) idx++;
		if (i + 1 > idx) {
		  X = next;
		  break;
		}
	}
	cout << X << endl;
	return 0;
}