#include <bits/stdc++.h>
#define ll long long
#define MAXN 100010
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

int N, K;
ll arr[MAXN], psa[MAXN << 1], ans;
deque<pair<ll, int>> minq;

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> K;
	for (int i=1; i<=N; i++) {
		cin >> arr[i];
		psa[i] = psa[i + N] = arr[i];
	}
	for (int i=1; i<=N << 1; i++) psa[i] += psa[i - 1];
	for (int i=1; i<N << 1; i++) {
		while (!minq.empty() && minq.back().f >= psa[i]) minq.pop_back();
		minq.push_back(mp(psa[i], i));
		while (!minq.empty() && minq.front().s < i - K) minq.pop_front();
		ans = max(ans, psa[i] - minq.front().f);
	}
	cout << ans << endl;
	return 0;
}