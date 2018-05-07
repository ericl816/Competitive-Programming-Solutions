#include <bits/stdc++.h>
#define ll long long
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define MAXM 710
#define MAXN 100
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

int N, ID, R;
int D[MAXN];

void Do_Test_Cases () {
	int TEST_CASES = 10;
	while (TEST_CASES--) {
		cin >> N;
		vi diam[MAXM];
		vi ans;
		int minn = INF;
		while (N--) {
			cin >> ID >> R;
			for (int i=0; i<R; i++) {
				cin >> D[i];
				diam[ID].pb(D[i]);
				minn = min(minn, D[i]);
			}
		}
		for (int i=0; i<R; i++) {
			for (size_t j=0; j<diam[i].size(); j++) {
				int &next = diam[i][j];
				if (next == minn) ans.pb(i);
			}
		}
		ans.erase(unique(ans.begin(), ans.end()), ans.end());
		sort(ans.begin(), ans.end());
		cout << minn << " {";
		for (auto i : ans) {
			cout << i;
			if (i != ans[ans.size() - 1]) cout << ",";
		}
		cout << "}" << "\n";
	}
}

int main () {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cout.tie(0);
    // freopen("DATA11.txt", "r", stdin);
    Do_Test_Cases();
    return 0;
}