#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define MAXN 40010
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
using namespace std;

int N;
ll a, num;
stack<pair<int, ll>> hill;
pair<int, ll> arr;

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i=0; i<N; i++) {
		cin >> a;
		arr = mp(1, a);
		while (!hill.empty()) {
			pair<int, ll> &curr = hill.top();
			if (a > curr.s) {
				num += curr.f;
				hill.pop();
			}
			else if (a == curr.s) {
				num += curr.f;
				arr.f += curr.f;
				hill.pop();
			}
			else break;
		}
		if (!hill.empty()) num++;
		hill.push(arr);
	}
	cout << num << endl;
	return 0;
}