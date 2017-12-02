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

struct Coor {
  int f, s;
  
  bool operator < (const Coor &e) const {
    if (f ^ e.f) return f < e.f;
    return s < e.s;
  }
};

bool Cmp (pii &a, pii &b) {
  if (a.f == b.f) return a.s < b.s;
  return a.f < b.f;
}

int N, X, T, I, J, bullets, xcoor = 1, moves, dist;
vector<pii> zombies;
bool killed, survive = 1;

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> X >> T;
	bullets = T;
	for (int i=0; i<N; i++) {
		cin >> I >> J;
		swap(I, J);
		zombies.push_back(mp(I, J));
	}
	sort(zombies.begin(), zombies.end(), Cmp);
	for (size_t i=0; i<zombies.size(); i++) {
		pii &next = zombies[i];
		dist = abs(xcoor - next.s);
		xcoor = next.s;
		moves += dist;
		if (bullets == 0) {
			// Reload
			bullets = T;
			moves++;
		}
		// Kill zombies
		bullets--;
		moves++;
		if (moves > next.f) {
			survive = 0;
			break;
		}
	}
	cout << (survive ? "You can do it, Ace!" : "Never lucky, Ace.") << endl;
	return 0;
}