#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
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

/*
 * The sequence of non-negative integers A1, A2, ..., AN is given. 
 * You are to find some subsequence Ai1, Ai2, ..., Aik (1 <= i1 < i2 < ... < ik <= N) such, 
 * that Ai1 XOR Ai2 XOR ... XOR Aik has a maximum value.
 */

int N, cnt;
ll ans;
ll A[MAXN];

int main () {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	scanf("%d", &N);
	for (int i=0; i<N; i++) scanf("%lld", A + i);
	for (int i=62; i>=0; i--) {
		for (int j=cnt; j<N; j++) {
			if (A[j] & (1LL << i)) {
				swap(A[j], A[cnt]);
				for (int k=0; k<N; k++) {
					if (cnt ^ k && (A[k] & (1LL << i))) A[k] ^= A[cnt];
				}
				cnt++;
				break;
			}
		}
	}
	for (int i=0; i<cnt; i++) ans ^= A[i];
	return !printf("%lld\n", ans);
}