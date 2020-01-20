#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
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

int ans = INF;
string s1, s2 = "DMOJ";
vector<string> res;

void subseq (int idx = -1, string s = "") {
	if (idx == 4) return;
	if (!s.empty()) res.pb(s);
	for (int i=idx + 1; i<4; i++) {
		s += s2[i];
		subseq(i, s);
		s = s.erase(s.size() - 1);
	}
	return;
}

int main () {
	cin.sync_with_stdio(0);
	cin >> s1;
	subseq();
	for (auto i : res) {
		size_t ind = s1.find(i);
		if (ind != string::npos) ans = min(ans, 4 - i.size());
	}
	cout << ans << "\n";
	return 0;
}