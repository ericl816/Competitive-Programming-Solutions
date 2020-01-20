#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXM 1010
#define MAXN 110
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

int r, c, cnt1, cnt2, ans;
string s;
char op[MAXN][MAXN];
bool flag;

int main () {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> r >> c;
	for (int i=0; i<r; i++) {
		cin >> s;
		for (int j=0; j<c; j++) op[i][j] = s[j];
	}
	for (int i=0; i<r; i++) {
		for (int j=0; j<c; j++) {
			if (op[i][j] == '.') {
				cnt1 = cnt2 = 0;
				for (int k=-1; k<=1; k++) {
					for (int l=-1; l<=1; l++) {
						if ((k || l) && i + k >= 0 && i + k < r && j + l >= 0 && j + l < c) {
							if (op[i + k][j + l] == '.') cnt1++;
							else cnt2++;
						}
					}
				}
				ans += cnt1 > cnt2;
			}
		}
	}
	cout << ans << "\n";
	return 0;
}