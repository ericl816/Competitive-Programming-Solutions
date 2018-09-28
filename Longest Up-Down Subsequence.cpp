#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXN 2000010
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

/*
 * DP works like this:
 * DP[0][i] = Length of the longest Zig-Zag subsequence
 * 		ending at index i and last element is greater
 *      than its previous element
 * DP[1][i] = Length of the longest Zig-Zag subsequence
        ending at index i and last element is smaller
        than its previous element

 * Overall Time Complexity: O(N)
 */

int N;
int arr[MAXN];
ll DP[2][MAXN];

int main () {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for (int i=0; i<N; i++) cin >> arr[i];
	for (int i=0; i<2; i++) for (int j=0; j<N; j++) DP[i][j] = 1LL;
	if (arr[0] < arr[1]) DP[0][1] = 2LL;
	else DP[1][1] = 2LL;
	for (int i=2; i<N; i++) {
		if (arr[i - 1] < arr[i]) DP[0][i] = max(DP[0][i - 1], DP[1][i - 1] + 1);
		else if (arr[i - 1] > arr[i]) DP[1][i] = max(DP[1][i - 1], DP[0][i - 1] + 1);
		else {
			DP[0][i] = DP[0][i - 1];
			DP[1][i] = DP[1][i - 1];
		}
	}
	cout << (max(DP[0][N - 1], DP[1][N - 1])) << "\n";
	return 0;
}