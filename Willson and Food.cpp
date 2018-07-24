#include <bits/stdc++.h>
#define ll long long
#define MAXN 100010
#define INF 0x3f3f3f3f
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define pllll pair<ll, ll>
#define mp make_pair
#define f first
#define s second
#define msll map<string, ll>
#define umsll unordered_map<string, ll>
#define sll set<ll>
using namespace std;

int F, N, dist, energy;
ll e[MAXN], d[MAXN], cnt;
string s, t;
msll val;
vector<pllll> type;
sll si;

bool compare (const pllll &a, const pllll &b) {
	return a.s < b.s;
}

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> F;
	for (int i=0; i<F; i++) {
		cin >> s >> e[i];
		val[s] = e[i];
	}
	cin >> N;
	for (int i=0; i<N; i++) {
		cin >> t >> d[i];
		ll energy = val[t];
		ll dist = d[i];
		type.pb(mp(energy, dist));
	}
	sort(type.begin(), type.end(), compare);
	for (int i=0; i<N; i++) {
		if (dist ^ type[i].s && 0 > energy - type[i].s + dist) break;
		else if (dist == type[i].s) energy += type[i].f;
		else {
			energy -= type[i].s - dist - type[i].f;
			dist = type[i].s;
		}
		cnt++;
	}
	cout << cnt << "\n";
	return 0;
}