#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXN 1010
#define INF 0x3f3f3f3f
#define EPS 0.00000000001
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

int N, M, X;
int n[MAXN], m[MAXN];
bool flag1, flag2, flag3;
double ans, avg=-1, avg1, sum, tmp, minnavg = 1000.0;

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M >> X;
	for (int i=0; i<N; i++) cin >> n[i];
	for (int i=0; i<M; i++) cin >> m[i];
	for (int i : n) sum += i;
	tmp = 1.0 * sum / N;
	for (int i : m) {
		if (i == 0) continue;
		flag1 = 1;
		for (int j : n) {
			if (j > 0 and j > i) {
				flag1 = 0;
				break;
			}
		}
		avg = 1.0 * tmp / i;
		if (avg + EPS < 0.5 or avg + EPS > 1.0 or avg + EPS < 0.3 or !flag1) {
			flag3 = 1;
			continue;
		}
		flag2 = 1;
		if (!flag3) avg1 = (int) round(1.0 * (abs(avg * 100.0 - 1.0 * X)));
		if (avg1 + EPS < minnavg) {
			minnavg = avg1;
			ans = i;
		}
		if (ans > 0.0 and minnavg != 1000.0 and fabs(avg1 - minnavg) < EPS) ans = i;
	}
	if (flag2) cout << ans << "\n";
	else if (!flag2 || flag3) cout << "Shimnanigans have failed" << "\n";
	return 0;
}