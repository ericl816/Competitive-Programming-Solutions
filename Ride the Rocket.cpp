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

// Greedy algorithms

ll N, P, B, C, M, W, ans, capacity, numbuses, buscost, walkcost;
vi D, T;

/*
N = # of bus stops from 1 to N
P = # of minutes for bus to arrive
B = # of minutes after a student uses the newly arrived bus
C = capacity of passengers on each of buses
M = # of students waiting at stop 1 initially
D[] = bus stops that the ith student wants to get to
W = # of minutes required to walk to the next stop
*/

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> P >> B >> C >> M >> W;
	for (int i=0, x; i<M; i++) {
		cin >> x;
		D.pb(x);
	}
	sort(D.begin(), D.end());
	if (W <= B) {
		for (int i=0; i<M; i++) ans += W * (D[i] - 1);
		cout << ans << endl;
		return 0;
	}
	if (M <= C) {
		for (int i=0; i<M; i++) ans += B * (D[i] - 1);
		cout << ans << endl;
		return 0;
	}
	capacity = C;
	for (int i=M - 1; i>=0; i--) {
		buscost = B * (D[i] - 1) + P * numbuses;
		walkcost = W * (D[i] - 1);
		if (walkcost <= buscost) ans += walkcost;
		else if (walkcost > buscost) {
			if (--capacity == 0) {
				numbuses++;
				capacity = C;
			}
			ans += buscost;
		}
	}
	cout << ans << endl;
	return 0;	
}