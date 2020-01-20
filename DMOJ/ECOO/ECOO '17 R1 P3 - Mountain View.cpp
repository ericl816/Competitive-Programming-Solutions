#include <bits/stdc++.h>
#define ll long long
#define MAXN 10010
#define INF 1000010
#define EPS 1e-20
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define mii map<int, int>
#define umii unordered_map<int, int>
using namespace std;

int N, ans, cnt, bestview;
int mountains[MAXN];
double slope1, slope2;

void Do_Test_Cases () {
	int n = 10;
	while (n--) {
		cin >> N;
		ans = bestview = 0;
		for (int i=0; i<N; i++) cin >> mountains[i];
		for (int i=0; i<N; i++) {
			slope1 = slope2 = -INF;
			cnt = 0;
			for (int j=i + 1; j<N; j++) {
				double res = 1.0 * (mountains[j] - mountains[i]) / (j - i);
				if (slope1 + EPS < res) {
					slope1 = res;
					cnt++;
				}
			}
			for (int j=i - 1; j>=0; j--) {
				double res = -1.0 * (mountains[j] - mountains[i]) / (j - i);
				if (slope2 + EPS < res) {
					slope2 = res;
					cnt++;
				}
			}
			if (bestview < cnt) {
				bestview = cnt;
				ans = i;
			}
		}
		cout << ans + 1 << "\n";
	}
}
int main () {
    cin.tie(0);
    cin.sync_with_stdio(0);
    Do_Test_Cases();
    return 0;
}