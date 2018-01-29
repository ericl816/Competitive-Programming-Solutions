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

int N, M, H, ans;
int T[MAXN];
bool flag;

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M >> H;
	for (int i=0; i<N; i++) cin >> T[i];
	sort(T, T + N);
	for (int i=N - 1; i>=1; i--) {
		while (abs(T[i - 1] - T[i]) > H) {
			ans++;
			T[i - 1] += M;
		}
	}
	cout << ans << endl;
	return 0;
}