#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define mii map<int, int>
#define umii unordered_map<int, int>
using namespace std;

int N, K;

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> K;
	if (N == K) {
		for (int i=1; i<=N; i++) cout << i << " ";
		cout << endl;
		return 0;
	}
	if (round(sqrt(N) > K)) {
		cout << -1 << endl;
		return 0;
	}
	for (int i=1; i<=(N + K - 1) / K; i++) for (int j=max(1, N - i * K + 1); j<N - i * K + 1 + K; j++) cout << j << " ";
	cout << endl;
	return 0;
}