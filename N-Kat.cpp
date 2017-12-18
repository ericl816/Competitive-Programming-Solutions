#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXM 20
#define MAXN 1 << MAXM
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

int N, arr[MAXM], bit1 = -1, bit2 = -1;
ll memo[MAXN];
bool vis[MAXN];

inline ll GetBit (ll a) {
	return 1 << a;
}

inline bool CheckBit (int mask, ll a) {
	return mask & GetBit(a);
}

inline ll SetBit (int mask, ll a) {
	return mask | GetBit(a);
}

void Generate (int mask, ll sum) {
	if (~memo[mask]) return;
	memo[mask] = sum;
	for (int i=0; i<N; i++) {
		if (CheckBit(mask, i)) goto outer;
		Generate(SetBit(mask, i), sum + arr[i]);
	}
	outer:;
}

void Partition (int mask) {
	if (bit1 ^ bit2 && memo[bit1] == memo[bit2]) return; // Already have the minimum optimal difference
	if (vis[mask] || __builtin_popcount(mask) > (N >> 1) + 1) return; // Can't be possible to divide into two subsets
	vis[mask] = 1;
	for (int cmask = (GetBit(N) - 1) &~ mask; cmask; cmask = (cmask - 1) & ((GetBit(N) - 1) ^ mask)) {
		if (abs(memo[bit1] - memo[bit2]) > abs(memo[mask] - memo[cmask]) || bit1 == -1) { // Get the minimum difference between two subsets
			bit1 = mask;
			bit2 = cmask;
        }
    }
	for (int i=0; i<N; i++) {
		if (CheckBit(mask, i)) continue;
		Partition(SetBit(mask, i));
	}
}

int main() {
	scan(N);
	for (int i=0; i<N; i++) scan(arr[i]);
	memset(memo, -1, sizeof(memo));
	Generate(0, 0);
	for (int i=0; i<N; i++) Partition(GetBit(i));
	for (int i=0; i<N; i++) if (CheckBit(bit1, i)) printf("%d ", i + 1);
	printf("\n");
	for (int i=0; i<N; i++) if (CheckBit(bit2, i)) printf("%d ", i + 1);
	printf("\n");
	return 0;
}