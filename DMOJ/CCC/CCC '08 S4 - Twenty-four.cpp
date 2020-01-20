#include <bits/stdc++.h>
#define ll long long
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

int N, ans;
int C[4];

void Recur (int idx, int curr, int next) {
	if (idx == 3) { // Don't go out of bounds
		if (curr + next <= 24) ans = max(ans, curr + next);
		if (curr - next <= 24) ans = max(ans, curr - next);
		if (curr * next <= 24) ans = max(ans, curr * next);
		if (next && curr % next == 0 && curr / next <= 24) ans = max(ans, curr / next);
		return;
	}
	// Recurse
	Recur(idx + 1, curr + next, C[idx + 1]);
	Recur(idx + 1, curr - next, C[idx + 1]);
	Recur(idx + 1, curr * next, C[idx + 1]);
	if (next && curr % next == 0) Recur(idx + 1, curr / next, C[idx + 1]);
	Recur(idx + 1, curr, next + C[idx + 1]);
	Recur(idx + 1, curr, next - C[idx + 1]);
	Recur(idx + 1, curr, next * C[idx + 1]);
	if (C[idx + 1] && next % C[idx + 1] == 0) Recur(idx + 1, curr, next / C[idx + 1]);
}

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i=0; i<N; i++) {
		ans = 0;
		for (int j=0; j<4; j++) cin >> C[j];
		sort(C, C + 4);
		do {
			Recur(1, C[0], C[1]);
		} while (next_permutation(C, C + 4));
		cout << ans << endl;
	}
	return 0;
}