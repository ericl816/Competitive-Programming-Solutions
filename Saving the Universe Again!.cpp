#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXM 1010
#define MAXN 5010
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

int T, d, dam = 1, tot, ans;
bool flag = 1;
string s;

inline int Calc (string seq) {
	dam = 1, tot = 0;
	for (size_t i=0; i<seq.size(); i++) {
		if (seq[i] == 'C') dam <<= 1;
		else tot += dam;
	}
	return tot;
}

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	for (int z=1; z<=T; z++) {
		cin >> d >> s;
		ans = 0;
		flag = 1;
		while (Calc(s) > d && flag) {
			flag = 0;
			for (size_t i=s.size() - 1; i>=1; i--) {
				if (s[i - 1] == 'C' && s[i] == 'S') {
					swap(s[i - 1], s[i]);
					flag = 1;
					break;
				}
			}
			ans++;
		}
		cout << "Case #" << z << ": ";
		if (Calc(s) <= d) cout << ans << "\n";
		else cout << "IMPOSSIBLE" << "\n";
	}
	return 0;
}
