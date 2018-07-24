#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXN 1000010
#define SEED 131
#define MOD 1000000007
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

string s, t;
ll hashed[MAXN], qpow[MAXN];

// Use this to get the hash of the current substring
inline ll Get_Hash_Substr (ll a, ll b) {
	if (a == 0) return hashed[b];
	else {
		ll len = b - a + 1;
		return hashed[b] - (hashed[a - 1] * qpow[len]);
	}
	return -1;
}

int main () {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> s >> t;
	qpow[0] = hashed[0] = 1LL;
	for (size_t i=1; i<=s.size(); i++) {
		hashed[i] = hashed[i - 1] * SEED + s[i - 1] - 'a' + 1;
		qpow[i] = qpow[i - 1] * SEED;
	}
	ll val = t[0] - 'a' + 1;
	for (size_t i=1; i<t.size(); i++) {
		val = val * SEED + t[i] - 'a' + 1;
	}
	int len = t.size();
	for (int l=1, r=l + len - 1; r<=s.size(); l++, r++) {
		if (hashed[r] - (hashed[l - 1] * qpow[r - l + 1]) == val) {
			cout << l - 1 << "\n";
			return 0;
		}
	}
	cout << -1 << "\n";
	return 0;
}
