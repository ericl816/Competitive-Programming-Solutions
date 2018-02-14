#include <bits/stdc++.h>
#define ll long long
#define MAXN 100010
#define INF 0x3f3f3f3f
using namespace std;

int N, t, ex, gr, go, ba, mi, f, cnt, last, maxx;
long double S, new_score, ans;
vector<int> v;
bool flag;

int main () {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> S;
    for (int i=1; i<=N; i++) {
    	cin >> t;
    	t = abs(t);
    	if (t <= 200) cnt++;
    	if (t >= 0 && t <= 50) ex++;
    	else if (t >= 51 && t <= 100) gr++;
    	else if (t >= 101 && t <= 150) go++;
    	else if (t >= 151 && t <= 200) ba++;
    	else if (t > 200) {
    	  mi++;
    	  cnt = 0;
    	}
    	maxx = max(maxx, cnt);
    }
    new_score = 1.0 * (1.5 * ex + gr + go + 0.5 * ba - mi + 0.5 * maxx);
    ans = 1.0 * (new_score - S);
    if (ans < 0) ans = 0;
    cout << setprecision(1) << fixed;
    cout << ans << endl;
    return 0;
}