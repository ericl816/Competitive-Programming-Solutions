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

int n, a, freq[MAXN];
bool flag;

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	while (n--) {
		cin >> a;
		freq[a]++;
	}
	for (int idx=1; idx<=1e5; idx++) {
		if (freq[idx] & 1) {
			cout << "Conan" << "\n";
			return 0;
		}
	}
	cout << "Agasa" << "\n";
	return 0;
}