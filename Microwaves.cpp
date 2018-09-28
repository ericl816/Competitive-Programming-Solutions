#include <bits/stdc++.h>
#define ll long long
#define MAXM 110
#define MAXN 1000010
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define mii map<int, int>
#define umii unordered_map<int, int>
using namespace std;

int N, M, T, t, f;
ll microwaves[MAXM];
pair<ll, ll> people[MAXN];

bool Cmp (pair<ll, ll> &a, pair<ll, ll> &b) {
	return a.f < b.f;
}

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M >> T;
	for (int i=0; i<M; i++) {
		cin >> t >> f;
		people[i] = mp(t, f);
	}
	sort(people, people + M, Cmp);
	for (int i=0; i<M; i++) {
		int it = upper_bound(microwaves, microwaves + N, people[i].f) - microwaves - 1;
		if (~it) {
		  if (people[i].f - microwaves[0] >= T) {
				cout << microwaves[0] << endl;
				return 0;
			}
			microwaves[it] = people[i].f + people[i].s;
		}
		else microwaves[0] += people[i].s;
		sort(microwaves, microwaves + N);
	}
	cout << microwaves[0] << endl;
	return 0;
}