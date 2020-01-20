#include <bits/stdc++.h>
#define ll long long
#define MAXN 200010
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

int N, minn = INF, num;
bool processed[MAXN];
string name;
vector<pair<string, int>> list1, list2;

void Do_Test_Cases () {
	int n = 10;
	while (n--) {
		list1.clear();
		cin >> N;
		if (N <= 1) {
			cout << 0 << "\n";
			continue;
		}
		for (int i=0; i<N; i++) {
			cin >> name;
			list1.pb(mp(name, i));
		}
		minn = INF;
		for (int i=0; i<N; i++) {
			list2.clear();
			memset(processed, 0, sizeof(processed));
			for (int j=0; j<N; j++) {
				if (j ^ i) list2.pb(mp(list1[j].f, list1[j].s - (j > i)));
			}
			sort(list2.begin(), list2.end());
			int num = N - 1;
			for (int i=0; i<list2.size(); i++) {
				if (!processed[i]) {
					int next = i;
					while (!processed[next]) {
						processed[next] = 1;
						next = list2[next].s;
					}
					num--;
				}
			}
			minn = min(minn, num);
		}
		cout << minn << "\n";
	}
}

int main () {
    cin.tie(0);
    cin.sync_with_stdio(0);
    Do_Test_Cases();
    return 0;
}