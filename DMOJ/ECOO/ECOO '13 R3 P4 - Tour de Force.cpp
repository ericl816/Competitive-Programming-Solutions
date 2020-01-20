#include <bits/stdc++.h>
#define ll long long
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define MAXN 1010
#define INF 0x3f3f3f3f
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

int N;
int DP[MAXN][15];
pii cards[MAXN];

inline int Recur (int idx, int streak) {
	int &val = DP[idx][streak];
	if (~val) return val;
	if (idx >= N - 1) {
		if (streak <= 7) return cards[N - 1].f + cards[N - 1].s;
		if (streak == 8) return cards[N - 1].f - 1;
		if (streak == 9) return -1;
	}
	if (streak == 8) return val = cards[idx].f + Recur(idx + 1, 0) - 1;
	if (streak == 9) return val = Recur(idx + 1, 0) - 1;
	return val = max(Recur(idx + 1, streak + 2) + cards[idx].f + cards[idx].s, Recur(idx + 1, 0) + cards[idx].f - 1);
}

void Do_Test_Cases () {
	int TEST_CASES = 10;
	while (TEST_CASES--) {
		scan(N);
		memset(DP, -1, sizeof(DP));
		for (int i=0; i<N; i++) {
			scan(cards[i].f); scan(cards[i].s);
		}
		printf("%d\n", Recur(0, 0));
	}
}

int main () {
    Do_Test_Cases();
    return 0;
}