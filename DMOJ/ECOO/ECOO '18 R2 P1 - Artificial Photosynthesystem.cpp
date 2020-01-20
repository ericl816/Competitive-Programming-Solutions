#include <bits/stdc++.h>
#define ll long long
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define MAXN 15
#define INF 0x3f3f3f3f
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define mii map<int, int>
#define umii unordered_map<int, int>
using namespace std;

int C, O, W, S, C1, O1, W1, S1, C2, O2, W2, S2, ans;
bool flag[MAXN][MAXN][MAXN][MAXN];

inline void DFS (int c, int o, int w, int s) {
	if (c < 0 || o < 0 || w < 0 || s < 0) return;
	if (flag[c][o][w][s]) return;
	flag[c][o][w][s] = 1;
	ans = max(ans, o);
	DFS(c - C1, o + O1, w - W1, s + S1);
	DFS(c + C2, o - O2, w + W2, s - S2);
}

void Do_Test_Cases () {
	int TEST_CASES = 10;
	while (TEST_CASES--) {
		memset(flag, 0, sizeof(flag));
		ans = 0;
		cin >> C >> O >> W >> S >> C1 >> W1 >> S1 >> O1 >> S2 >> O2 >> C2 >> W2;
		DFS(C, O, W, S);
		cout << ans << "\n";
	}
}

int main () {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("DATA11.txt", "r", stdin);
    Do_Test_Cases();
    return 0;
}