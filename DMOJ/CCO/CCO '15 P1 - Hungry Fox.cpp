#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define ull unsigned long long
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
#ifdef DEBUG
	#define D(x...) printf(x)
#else
	#define D(x...)
#endif
using namespace std;

int N;
ll W, minn, maxx, maxx1, maxx2;
ll T[MAXN];
bool hotter = 1, colder = 1;

int main (int argc, char const *argv[]) {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> W;
	for (int i=0; i<N; i++) {
		cin >> T[i];
		hotter &= T[i] > W;
		colder &= T[i] < W;
	}
	if (hotter) sort(T, T + N);
	else if (colder) sort(T, T + N, greater<int>());
	if (hotter ^ colder) minn = abs(T[N - 1] - W);
	else minn = abs(T[N - 1] - T[0]);
	sort(T, T + N);
	int lo = 0, hi = N - 1, prevv = W;
	bool flag = 1;
	while (lo <= hi) {
		int next = flag ? lo : hi;
		maxx1 += max(abs(W - T[next]), abs(prevv - T[next]));
		prevv = T[next];
		if (flag) lo++;
		else hi--;
		flag ^= 1;
	}
	lo = 0, hi = N - 1, prevv = W;
	flag = 0;
	while (lo <= hi) {
		int next = flag ? lo : hi;
		maxx2 += max(abs(W - T[next]), abs(prevv - T[next]));
		prevv = T[next];
		if (flag) lo++;
		else hi--;
		flag ^= 1;
	}
	maxx = max(maxx1, max(maxx2, abs(T[N - 1] - T[0])));
	cout << minn << " " << maxx << "\n";
	return 0;
}

/* 
 * Look for:
 * the exact constraints (multiple sets are too slow for n=10^6 :( ) 
 * special cases (n=1?)
 * overflow (ll vs int?)
 * array bounds
 */