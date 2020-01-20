#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("avx")
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXM 510
#define MAXN 25010
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define mii map<int, int>
#define umii unordered_map<int, int>
using namespace std;

int N, idx;
vi h = vi(MAXM);
bool DP[MAXN + 1][2];
set<int> pillars;

int main () {
	scan(N);
	for (int i=0; i<N; i++) scan(h[i]);
	sort(h.begin(), h.end());
	reverse(h.begin(), h.end());
	DP[0][1] = 1;
	for (int i=1; i<N; i++) {
		for (int j=0; j<=MAXN; j++) {
			idx = i & 1;
			if (DP[j][idx ^ 1]) DP[j][idx] = 1;
			for (int next : pillars) {
				int val = next - h[i];
				if (j - val < 0) continue;
				if (DP[j - val][idx ^ 1]) DP[j][idx] = 1;
			}
		}
		pillars.insert(h[i]);
	}
	for (int i=0; i<=MAXN; i++) if (DP[i][(N & 1) ^ 1]) printf("%d ", i);
	printf("\n");
	return 0;
}