#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define mii map<int, int>
#define umii unordered_map<int, int>
using namespace std;

int N, cost, factor, root, quo;

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	while (N > 1) {
		root = ceil(sqrt(N));
		factor = 2;
		while (factor <= root && N % factor != 0) factor++;
		if (factor < N && N % factor == 0) {
			quo = N / factor;
			N -= quo;
			cost += N / quo;
		}
		else cost += --N;
	}
	cout << cost << endl;
	return 0;
}