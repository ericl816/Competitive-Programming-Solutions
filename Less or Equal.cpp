#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXN 200010
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

int n, k, ans;
int a[MAXN];

int countLessEqual(int x) {
	int lo = 0, hi = n - 1;
	while (lo <= hi) {
		int mid = (lo + hi) >> 1;
		if (a[mid] <= x) lo = mid + 1;
		else hi = mid - 1;
	}
	return lo;
}

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	for (int i=0; i<n; i++) cin >> a[i];
	sort(a, a + n);
	int lo = 1, hi = 1e9;
	while (lo <= hi) {
		int mid = (lo + hi) >> 1;
		int temp = countLessEqual(mid);
		if (temp == k) {
			cout << mid << "\n";
			return 0;
		}
		else if (temp < k) lo = mid + 1;
		else hi = mid - 1;
	}
	cout << -1 << "\n";
	return 0;
}