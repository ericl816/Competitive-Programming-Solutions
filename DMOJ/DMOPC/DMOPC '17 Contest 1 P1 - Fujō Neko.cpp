#include <bits/stdc++.h>
#define ll long long
#define MAXN 1010
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
using namespace std;

int R, C, Q, x, y;
char ch[MAXN][MAXN];
bool rows[MAXN], col[MAXN];

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> R >> C;
	for (int i=1; i<=R; i++) {
		for (int j=1; j<=C; j++) {
			cin >> ch[i][j];
			if (ch[i][j] == 'X') rows[j] = col[i] = 1;
		} 
	}
	cin >> Q;
	for (int i=0; i<Q; i++) {
	  cin >> x >> y;
	  cout << (rows[x] || col[y] ? "Y" : "N") << "\n";
	}
	return 0;
}