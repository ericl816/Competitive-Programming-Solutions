#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define ull unsigned long long
#define MAXN 10
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
#define println cout << "\n";
#ifdef DEBUG
	#define D(x...) printf(x)
#else
	#define D(x...)
#endif
using namespace std;

int T, G, a, b, sa, sb, idx, ans;
int scores[MAXN];
pii games[MAXN];
bool flag[MAXN][MAXN];

inline void Solve (int num) {
	if (num == idx) {
		int res = scores[T];
		for (int i=0; i<4; i++) {
			if (i == T) continue;
			if (scores[i] >= res) return;
		}
		ans++;
		return;
	}
	int tmp1 = games[num].f, tmp2 = games[num].s;
	scores[tmp1] += 3;
	Solve(num + 1);
	scores[tmp1] -= 3;
	scores[tmp2] += 3;
	Solve(num + 1);
	scores[tmp2] -= 3;
	scores[tmp1]++, scores[tmp2]++;
	Solve(num + 1);
	scores[tmp1]--, scores[tmp2]--;
}

int main (int argc, char const *argv[]) {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T >> G;
	--T;
	for (int i=0; i<G; i++) {
		cin >> a >> b >> sa >> sb;
		--a, --b;
		if (sa > sb) scores[a] += 3;
		else if (sa < sb) scores[b] += 3;
		else {
			scores[a]++, scores[b]++;
		}
		flag[a][b] = 1;
	}
	for (int i=0; i<4; i++) {
		for (int j=i + 1; j<4; j++) {
			if (!flag[i][j]) {
				games[idx++] = mp(i, j);
			}
		}
	}
	Solve(0);
	cout << ans << "\n";
	return 0;
}

/* 
 * Look for:
 * the exact constraints (multiple sets are too slow for n=10^6 :( ) 
 * special cases (n=1?)
 * overflow (ll vs int?)
 * array bounds
 */