#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXN 1010
#define INF 0x3f
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define umii unordered_map<int, int>
#define mii map<int, int>
using namespace std;

int L, D, x, y, DP[MAXN][MAXN], coor[MAXN][MAXN];
int *movex = new int[3] {-1, 1, 0}, *movey = new int[4] {0, 0, 1};
queue<pii> q;
bool vis[MAXN][MAXN];

int main () {
	scan(L); scan(D);
	memset(DP, INF, sizeof(DP));
	for (int i=0; i<D; i++) for (int j=0; j<L; j++) cin >> coor[i][j];
	scan(x); scan(y);
	swap(x, y);
	DP[0][0] = coor[0][0];
	vis[0][0] = 1;
	q.push(mp(0, 0));
	while (!q.empty()) {
		pii curr = q.front();
		q.pop();
		for (int i=0; i<3; i++) {
			int currx = curr.f;
			int curry = curr.s;
			vis[curry][currx] = 0;
			int len = currx + movex[i];
			int depth = curry + movey[i];
			if (len >= L || len < 0 || depth >= D || depth < 0) continue;
			if (DP[curry][currx] + coor[depth][len] < DP[depth][len]) {
				DP[depth][len] = DP[curry][currx] + coor[depth][len];
				if (!vis[depth][len]) {
					vis[depth][len] = 1;
					q.push(mp(len, depth));
				}
			}
		}
	}
	return 0 * printf("%d\n", DP[x][y]);
}