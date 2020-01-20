#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("avx")
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
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

ll R, C, K, Q, snow[53][2003];
int type, a, b, c, d, v;
bool blocked[53][2003];
queue<pair<int, int>> q;
unordered_set<int> queued;

void Insert (int x, int y) {
	if (x > 0 && y > 0 && x <= R && y <= C && !blocked[x][y] && queued.find(x * 2003 + y) == queued.end()) {
		q.push(mp(x, y));
		queued.insert(x * 2003 + y);
	}
}

void Update() {
	while (!q.empty()) {
		pii p = q.front();
		q.pop();
		int x = p.first;
		int y = p.second;
		queued.erase(x * 2003 + y);
		bool state = 1;
		if (x != 1 && !blocked[x - 1][y]) state = 0;
		if (y != 1 && !blocked[x][y - 1]) state = 0;
		if (state) {
			blocked[x][y] = 1;
			Insert(x + 1, y);
			Insert(x, y + 1);
		}
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> R >> C >> K >> Q;
	for (int i = 0; i < Q;i++) {
		cin >> type >> a >> b >> c >> d;
		if (type == 1) {
			cin >> v;
			for (int x=a; x<=c; x++) {
				for (int y=b; y<=d; y++) {
					snow[x][y] += (ll) v;
					if (snow[x][y] >= K) blocked[x][y] = 1;
				}
			}
			for (int x=a; x<=c; x++) {
				for (int y=b; y<=d; y++) {
					if (snow[x][y] >= K && snow[x][y] - (ll) v < K) {
						Insert(x + 1, y);
						Insert(x, y + 1);
					}
				}
			}
		}
		else {
			Update();
			if (blocked[c][d]) printf("no\n");
			else printf("yes\n");
		}
	}
	return 0;
}