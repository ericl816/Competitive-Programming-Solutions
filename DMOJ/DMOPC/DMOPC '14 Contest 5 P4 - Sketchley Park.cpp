#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXN 500010
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
int N, len;
string s, key, ans, msg = "HAILHYDRA";
int T[MAXN];
map<char, int> dict;
inline void KMP_Preprocess () {
	T[0] = -1;
	int i = 0, j = -1;
	while (i < 9) {
		while (j >= 0 && msg[i] != msg[j]) j = T[j];
		T[++i] = ++j;
	}
}
inline bool KMP () {
	int i = 0, j = 0;
	while (i < len) {
		while (j >= 0 && ans[i] != msg[j]) j = T[j];
		i++, j++;
		if (j == 9) return 1;
	}
	return 0;
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
	len = s.size();
	ans = s;
	cin >> N;
	KMP_Preprocess();
	for (int i=0; i<N; i++) {
		cin >> key;
		for (int j=0; j<26; j++) dict[key[j]] = j;
		for (int j=0; j<len; j++) ans[j] = 'A' + dict[s[j]];
		// cout << ans << "\n";
		if (KMP()) {
			cout << ans << "\n";
			return 0;
		}
	}
	cout << "KeyNotFoundError\n";
	return 0;
}