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

int N, a, b;
vector<pii> vec1, vec2;

inline bool Cmp (pii &a, pii &b) {
	return a.f < b.f;
}

int main () {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for (int i=0; i<N; i++) {
		cin >> a >> b;
		vec1.pb(mp(a, i));
		vec2.pb(mp(b, i));
	}
	sort(vec1.begin(), vec1.end(), Cmp);
	sort(vec2.begin(), vec2.end(), Cmp);
	for (size_t i=0; i<vec1.size(); i++) cout << vec1[i].s + 1 << " ";
	cout << endl;
	for (size_t i=0; i<vec2.size(); i++) cout << vec2[i].s + 1 << " ";
	return 0;
}