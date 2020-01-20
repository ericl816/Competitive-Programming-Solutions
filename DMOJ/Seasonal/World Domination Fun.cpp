#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXM 1000000010
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

int N, M, K;
ll h[MAXN], diff[MAXN];

inline ll LargestStrength (ll n) {
	memset(diff, 0, sizeof(diff));
	ll val = 0;
	for (int i=1; i<=N; i++) {
		diff[i] += diff[i - 1];
		if (diff[i] + h[i] < n) {
			val += n - (diff[i] + h[i]);
			if (i + M <= N) diff[i + M] -= n - (diff[i] + h[i]);
			diff[i] += n - (diff[i] + h[i]);
		}
	}
	return val;
}

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M >> K;
	for (int i=1; i<=N; i++) cin >> h[i];
	ll lo = 0, hi = MAXM << 1;
	while (lo <= hi) {
		ll mid = (lo + hi) >> 1;
		if (LargestStrength(mid) > K) hi = mid - 1;
		else lo = mid + 1;
	}
	cout << hi << endl;
	return 0;
}