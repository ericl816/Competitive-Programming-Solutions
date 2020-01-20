#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXN 10010
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

int L, len;
int T[MAXN];
string s, ans;
vector<string> vec;
map<string, vi> ind;

inline void KMP_Preprocess (string t) {
	T[0] = -1;
	for (int i=0, j=-1; i<t.size(); i++, j++, T[i] = j) {
		while (j >= 0 && t[i] != t[j]) j = T[j];
	}
}

inline void KMP (string t) {
	for (int i=0, j=0; i<s.size(); i++, j++) {
		while (j >= 0 && s[i] != t[j]) j = T[j];
		if (j == t.size() - 1) {
			ind[t].pb(abs(i - j));
		}
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
	cin >> L >> s;
	for (size_t i=0; i<L; i++) {
		for (size_t j=1; j<=L - i; j++) {
			string t = s.substr(i, j);
			vec.pb(t);
		}
	}
	for (auto i : vec) {
		KMP_Preprocess(i);
		KMP(i);
	}
	for (auto i : vec) {
		if (ind[i].size() >= 2) {
			if (len < i.size()) len = i.size();
		}
	}
	cout << len << endl;
	return 0;
}