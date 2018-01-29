#include <bits/stdc++.h>
#define ll long long
#define MAXN 100010
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define mii map<int, int>
#define umii unordered_map<int, int>
using namespace std;

int N, a[MAXN], b[MAXN], minn, maxx = 0x3f3f3f3f, res;
bool flag;

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i=0; i<N - 1; i++) {
		cin >> a[i] >> b[i];
		minn += b[i];
	}
	minn = max(0, a[0] - minn);
	res = a[0];
	for (int i=1; i<N - 1; i++) {
		res -= b[i];
		maxx = min(maxx, res);
		res += a[i];
	}
	cout << minn << endl << maxx << endl;
	return 0;
}