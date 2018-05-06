#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
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

int n;
int a[MAXN];
ll freq[MAXN], DP[MAXN];

inline ll Solve (int idx) {
	if (idx >= MAXN) return 0;
	ll &val = DP[idx];
	if (~val) return val;
	return val = max(Solve(idx + 1), idx * freq[idx] + Solve(idx + 2));
}

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	memset(DP, -1, sizeof(DP));
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i];
		freq[a[i]]++;
	}
	cout << Solve(0) << "\n";
	return 0;
}