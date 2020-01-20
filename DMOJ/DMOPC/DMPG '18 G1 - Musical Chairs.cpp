#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXN 1000010
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
int N, K, ans;
vector<pii> chairs;
stack<pii> st;
inline bool Cmp (pii &a, pii &b) {
	if (a.f == b.f) return b < a;
	return a < b;
}
int main () {
	scan(N); scan(K);
	for (int i=1, ind; i<=K; i++) {
		scan(ind);
		chairs.pb(mp(ind, 0));
	}
	for (int i=1, x; i<=K + 1; i++) {
		scan(x);
		chairs.pb(mp(x, i));
	}
	sort(chairs.begin(), chairs.end(), Cmp);
	for (size_t i=0; i<chairs.size(); i++) {
		pii &next = chairs[i];
		if (!st.empty()) {
			if (next.s || st.top().s == 0) st.push(next);
			else st.pop();
		}
		else st.push(next);
	}
	while (!st.empty() && st.top().s) {
		ans = st.top().s;
		st.pop();
	}
	return !printf("%d\n", ans);
}