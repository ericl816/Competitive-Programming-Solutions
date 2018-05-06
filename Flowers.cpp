#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXN 100010
#define INF 0x3f3f3f3f
#define MOD 1000000007
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

int t, k, a, b;
ll PSA[MAXN];

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> t >> k;
	PSA[0] = 1;
	for (int i=1; i<MAXN; i++) {
		PSA[i] = (PSA[i] + PSA[i - 1]) % MOD;
		if (i >= k) PSA[i] = (PSA[i] + PSA[i - k]) % MOD;
	}
	for (int i=1; i<MAXN; i++) PSA[i] = (PSA[i] + PSA[i - 1]) % MOD;
	for (int i=0; i<t; i++) {
		cin >> a >> b;
		cout << ((PSA[b] - PSA[a - 1] + MOD) % MOD) << "\n";
	}
	return 0;
}