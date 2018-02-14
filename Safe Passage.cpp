#include <bits/stdc++.h>
#define ll long long
#define MAXN 20
#define INF 0x3f3f3f3f
#define min(a, b) (a) < (b) ? (a) : (b)
#define max(a, b) (a) < (b) ? (b) : (a)
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define mii map<int, int>
#define umii unordered_map<int, int>
using namespace std;

// NOTE: This solution is heavily based on observation and not on bitmask DP, which is the intended solution

int N;
int DP[MAXN], arr[MAXN];

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	memset(DP, INF, sizeof(DP));
	for (int i=0; i<N; i++) cin >> arr[i];
	sort(arr, arr + N);
	DP[0] = arr[0];
	DP[1] = arr[1];
	// Since they have to travel at the slower pace
	if (N == 2) {
		cout << DP[1] << endl;
		return 0;
	}
	if (N == 3) {
		cout << arr[0] + arr[1] + arr[2] << endl;
		return 0;
	}
	DP[2] = arr[0] + arr[1] + arr[2];
	for (int i=3; i<N; i++) DP[i] = min(DP[i - 1] + arr[i] + DP[0], DP[i - 2] + DP[0] + (DP[1] << 1) + arr[i]);
	cout << DP[N - 1] << endl;
	return 0;
}