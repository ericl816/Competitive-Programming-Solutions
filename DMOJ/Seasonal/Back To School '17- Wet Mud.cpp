#include <bits/stdc++.h>
#define ll long long
#define MAXN 100010
#define INF 0x3f3f3f3f
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
using namespace std;

int N, M, J, DP[MAXN], dist[MAXN];
pii arr[MAXN];
priority_queue<pii, vector<pii>, greater<pii>> pq;

int main () {
	scanf("%d %d %d", &N, &M, &J);
	for (int i=1; i<=M; i++) scanf("%d %d", &arr[i].f, &arr[i].s);
	sort(arr, arr + M + 1);
	memset(DP, INF, sizeof(DP));
	for (int i=M; i>=0; i--) {
		int inches = arr[i].f;
		int minutes = arr[i].s;
		dist[i] = J + inches;
		while (!pq.empty() && dist[i] < pq.top().s) pq.pop();
		if (N < dist[i]) DP[i] = minutes;
		if (!pq.empty()) DP[i] = min(DP[i], pq.top().f);
		DP[i] = max(DP[i], minutes);
		pq.push(mp(DP[i], inches));
	}
	return 0 * printf("%d\n", DP[0] ^ INF ? DP[0] : -1);
}