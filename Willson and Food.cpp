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

struct PLLLL {
  ll f, s;
};

int F, N, dist, energy;
ll e[MAXN], d[MAXN], cnt;
string s, t;
msll val;
vector<pllll> type;
sll si;
bool flag;

ll Recurse (int idx, vector<pllll> type, ll cnt, ll energy, ll dist) {
	sll::iterator it = si.begin();
	if (type.size() > idx && si.size() > idx && (!type[idx].f || energy + type[idx].f) && !flag) return Recurse(idx + 1, type, cnt + 1, energy + type[idx].f + dist, dist);
	else if (type.size() > idx && type[idx].f && type[idx].s - dist <= energy && flag) return Recurse(idx + 1, type, cnt + 1, energy + type[idx].f - type[idx].s + dist, type[idx].s);
	return cnt;
}

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
		if (dist != d[i - 1]) flag = 1;
		type.pb(mp(energy, dist)); //First = energy, second = distance required
		si.insert(dist);
	}
	sort(type.begin(), type.end(), compare);
	for (int i=0; i<N; i++) {
		if (dist ^ type[i].s && 0 > energy - type[i].s + dist) break; //Different distances
		else if (dist == type[i].s) energy += type[i].f; //Equal distances
		else {
			energy = energy - type[i].s + dist + type[i].f;
			dist = type[i].s;
		}
		cnt++;
	}
	//cout << Recurse(0, type, 0, 0, 0) << "\n";
	cout << cnt << "\n";
	return 0;
}