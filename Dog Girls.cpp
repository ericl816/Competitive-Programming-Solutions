#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
// #include <bits/stdc++.h>
#include "/Users/ericliu/Desktop/Competitive-Programming-Templates/stdc++.h"
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXM 1010
#define MAXN 5010
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

/*
 * Question asks for the number of distinct substrings of S that have a length of at least 2
 * We need to be able to keep track of the visited indices of the array
 * We need a set or a map to store the hash for the indices of each substring
 * If we don't have the substring later on, then we continue
 * To get the number of distinct substrings, store it in a set
 * Alternatively, we can also use KMP to find the index of the substring
 */

string s;
set<ll> cnt;
ll idx;
map<ll, ll> mm; // Keep track of the previous hashes
ll T[MAXN];
vector<string> ans;
ll hashed[MAXN], qpow[MAXN];

// Can use this to get the index of a same substring
inline int KMP (string s, string t) {
	for (int i=0, j=0; i<s.size(); i++, j++) {
		while (j >= 0 && s[i] != t[j]) j = T[j];
		if (j == t.size() - 1) return abs(i - j);
	}
}

// Use this to initialize KMP
inline void Init_KMP (string t) {
	T[0] = -1;
	for (int i=0, j=-1; i<t.size(); i++, j++, T[i] = j) {
		while (i >= 0 && t[i] != t[j]) j = T[j];
	}
}

inline int Get_Hash_Substr (ll a, ll b) {
	if (a == 0) return hashed[b];
	else {
		ll len = b - a + 1;
		return ((hashed[b] - (hashed[a - 1] * qpow[len]) % MOD) + MOD) % MOD;
	}
}

int main () {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> s;
	for (int i=0; i<s.size(); i++) {
		hashed[i + 1] = ((((hashed[i] * SEED + s[i]) % MOD) + MOD) % MOD);
		qpow[i] = (((qpow[i - 1] * SEED) % MOD) + MOD) % MOD;
	}
	// Init_KMP(s); 
	// Initialize KMP for the sink substring
	// We can directly increment it by 2
	idx = 0;
	for (int i=1; i+2<=s.size(); i++) {
		ll lo = 0;
		ll hi = s.size() - 1;
		cout << lo << " " << hi << endl;
		while (lo <= hi) {
			ll mid = (lo + hi) >> 1;
			// cout << mid << endl;
			ll hash1 = Get_Hash_Substr(i, i + mid);
			ll hash2 = Get_Hash_Substr(idx, idx + mid);
			if (hash1 == hash2) lo = mid + 1;
			else hi = mid - 1;
		}
		if (s[i + lo] < s[idx + lo]) idx = i;
		ans.pb(s.substr(idx, lo));
	}
	for (auto i : ans) cout << i << " ";
	return 0;
}