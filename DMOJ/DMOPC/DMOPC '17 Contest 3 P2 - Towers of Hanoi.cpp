#include <bits/stdc++.h>
#define ll long long
#define MAXN 100010
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

int N;
bool arr[MAXN];
vi steps;

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i=0; i<N; i++) cin >> arr[i];
	for (int i=1; i<N; i++) {
		if (arr[i - 1]) {
			steps.pb(i);
			arr[i - 1] ^= 1;
			arr[i] ^= 1;
			arr[i + 1] ^= 1;
		}
	}
	if (arr[N - 1]) {
		steps.pb(0);
		arr[0] ^= 1;
		arr[1] ^= 1;
		for (int i=1; i<N; i++) {
			if (arr[i - 1]) {
				steps.pb(i);
				arr[i - 1] ^= 1;
				arr[i] ^= 1;
				arr[i + 1] ^= 1;
			}
		}
	}
	cout << steps.size() << endl;
	for (int &next : steps) cout << next + 1 << endl;
	return 0;
}