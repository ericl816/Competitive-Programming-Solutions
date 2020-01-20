#include <bits/stdc++.h>
#define ll long long
#define MAXN 5010
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

int N, p, q, r, s;
ll cnt;
bool flag;
short psa[MAXN][MAXN];

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i=0; i<N; i++) {
		cin >> p >> q >> r >> s;
		psa[p][q]++;
		psa[r][s]++;
		psa[p][s]--;
		psa[r][q]--;
	}
	for (int i=1; i<MAXN; i++) for (int j=1; j<MAXN; j++) psa[i][j] += psa[i - 1][j] + psa[i][j - 1] - psa[i - 1][j - 1];
	for (int i=1; i<MAXN; i++) for (int j=1; j<MAXN; j++) if ((psa[i][j] > 0) + (psa[i - 1][j] > 0) + (psa[i][j - 1] > 0) + (psa[i - 1][j - 1] > 0) == 1) cnt++;
	cout << cnt << endl;
	return 0;
}