#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
// #include <bits/stdc++.h>
#include "/Users/ericliu/Desktop/Competitive-Programming-Templates/stdc++.h"
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXM 1010
#define MAXN 5010
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

int N, M, ans;
string W;
vector<string> D;

int main () {
	#ifdef NOT_DMOJ
	freopen("DATA11.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M >> W;
	for (int i=0; i<M; i++) {
		string x;
		cin >> x;
		for (int j=1; j<=25; j++) {
			bool flag = 1;
			for (int k=0; k<N && flag; k++) {
				if (W[k] == '?') continue;
				if ((W[k] - 'a' + j) % 26 != x[k] - 'a') flag = 0;
			}
			if (flag) {
				ans++;
				break;
			}
		}
	}
	cout << ans << endl;
	return 0;
}