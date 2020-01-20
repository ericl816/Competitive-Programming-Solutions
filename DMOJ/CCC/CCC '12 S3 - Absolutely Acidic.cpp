#include <bits/stdc++.h>
#define ll long long
#define MAXN 1010
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define mii map<int, int>
using namespace std;

int N, R, ans;
mii freq;
priority_queue<pii> pq;

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i=0; i<N; i++) {
		cin >> R;
		freq[R]++;
	}
	for (auto i : freq) pq.push(mp(i.s, i.f));
	pii highest1 = pq.top();
	pq.pop();
	pii highest2 = pq.top();
	while (pq.top().f == highest2.f) {
		highest2 = pq.top();
		pq.pop();
		ans = max(ans, abs(highest1.s - highest2.s));
	}
	cout << ans << endl;
	return 0;
}