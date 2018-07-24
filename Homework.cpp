#include <bits/stdc++.h>
#define ll long long
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define MAXN 1000010
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

int N, D;
set<int> available;
bool flag;
vector< pair <double, int > > vec;
double W, ans;

void Do_Test_Cases () {
	int TEST_CASES = 10;
	while (TEST_CASES--) {
		available.clear();
		flag = 0;
		for (int i=0; i<=MAXN; i++) available.insert(i);
		cin >> N;
		for (int i=0; i<N; i++) {
			cin >> D >> W;
			vec.pb(mp(W, D));
		}
		sort(vec.begin(), vec.end());
		reverse(vec.begin(), vec.end());
		ans = 0;
		for (pair<double, int> next : vec) {
			auto it = available.lower_bound(next.s);
			if (it == available.begin()) flag = 1;
			if (!flag) {
				ans += 1.0 * next.f;
				available.erase(prev(it));
			}
		}
		cout << fixed << setprecision(4) << ans << "\n";
	}
}

int main () {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("DATA21.txt", "r", stdin);
    Do_Test_Cases();
    return 0;
}

/*
3
1 1.0
2 1.0
3 1.0
5
1 2.0
1 1.0
3 3.0 
7 10.0
3 2.0
*/