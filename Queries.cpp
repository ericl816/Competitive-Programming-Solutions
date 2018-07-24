#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
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

int T, N, M, x, y, maxx, maxy;
string s;
bool flag;

int main () {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while (T--) {
		cin >> N >> M;
		flag = 0;
		s = "";
		for (int i=0; i<M; i++) {
			cin >> x >> y;
			if (x + y > N || (x == 0 && y == 0)) flag = 1;
			maxx = max(maxx, x);
			maxy = max(maxy, y);
			if (maxx + maxy > N) flag = 1;
		}
		if (flag) cout << -1 << "\n";
		else {
			for (int i=0; i<maxx; i++) s += "a";
			for (int i=0; i<maxy; i++) s += "b";
			if ((int) s.size() < N) for (size_t i=s.size(); i<N; i++) s += "a";
			cout << s << "\n";
		}
	}
	return 0;
}