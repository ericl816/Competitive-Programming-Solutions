#include <bits/stdc++.h>
#define ll long long
#define MAXN 3000010
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

int N, K, arr[MAXN];
ll ans;
deque<int> minq, maxq;

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> K;
	for (int i=0; i<N; i++) cin >> arr[i];
	for (int i=0, left=0; i<N; i++) {
		while (!minq.empty() && arr[i] < minq.back()) minq.pop_back();
		minq.push_back(arr[i]);
		while (!maxq.empty() && arr[i] > maxq.back()) maxq.pop_back();
		maxq.push_back(arr[i]);
		while (left < i && maxq.front() - minq.front() > K) {
			if (!minq.empty() && arr[left] == minq.front()) minq.pop_front();
			if (!maxq.empty() && arr[left] == maxq.front()) maxq.pop_front();
			left++;
		}
		ans += i - left + 1;
	}

	cout << ans << endl;
	return 0;
}