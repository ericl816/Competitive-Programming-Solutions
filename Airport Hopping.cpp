#include <bits/stdc++.h>
#define MAXN 100010
#define INF 0x3f3f3f3f
#define ll long long
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define mii map<int, int>
#define umii unordered_map<int, int>
using namespace std;

int N, M, A, B, C, ans_day, ans_minutes, minn = INF;
vector<pii> airports[MAXN];

inline void Calc (int airport) {
	minn = INF;
	for (size_t i=0; i<airports[airport].size(); i++) {
		pii &next = airports[airport][i];
		if (ans_minutes + 20 <= next.f * 60) {
			int nexttime = next.f * 60 + next.s * 60 + 20 - ans_minutes;
			if (minn > nexttime) minn = nexttime;
		}
		else if (ans_minutes + 20 <= 60 * 24 + next.f * 60) {
			int nexttime = 60 * 24 + next.f * 60 + next.s * 60 + 20 - ans_minutes;
			if (minn > nexttime) minn = nexttime;
		}
		else {
			int nexttime = 120 * 60 * 24 + next.f * 60 - ans_minutes;
			if (minn > nexttime) minn = nexttime;
		}
	}
	ans_minutes += minn;
	if (ans_minutes >= 60 * 24) {
		ans_day += ans_minutes / (60 * 24);
		ans_minutes %= (60 * 24);
	}
}

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	for (int i=0; i<M; i++) {
		cin >> A >> B >> C;
		airports[A].pb(mp(B, C));
	}
	for (int i=1; i<N; i++) Calc(i);
	cout << "Day " << ans_day << " Hour " << ceil(1.0 * ans_minutes / 60) << endl;
	return 0;
}