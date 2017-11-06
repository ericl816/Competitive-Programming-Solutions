#include <bits/stdc++.h>
#define ll long long
#define MAXN 100010
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
using namespace std;

struct Disjoint {
private:
	int N;
	vi lead, rank;

public:
	Disjoint(int N) : N(N), lead(N + 1), rank(N + 1) { }

	void make_Set () {
		for (int i=1; i<=N; i++) {
			lead[i] = i;
			rank[i] = 0;
		}
	}
	
	// Path Compression
	int Find (int x) {
		while (x ^ lead[x]) {
			lead[x] = lead[lead[x]];
			x = lead[x];
		}
		return x;
	}

	bool Merge (int x, int y) {
		int c = Find(x);
		int d = Find(y);
		if (c ^ d) return 1;
		return 0;
	}

	void Union (int x, int y) {
		int c = Find(x);
		int d = Find(y);
		if (c ^ d) {
			// Only merge the set with a smaller rank
			if (rank[c] > rank[d]) lead[d] = c;
			else {
				lead[c] = d;
				rank[d] = rank[d] + (rank[d] == rank[c]);
			}
		}
	}
}; 

Disjoint ds(MAXN);

int N, M, K, x, y;
vi people;

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	ds.make_Set();
	for (int i=1; i<=M; i++) {
		cin >> K >> x;
		for (int i=1; i<K; i++) {
		  cin >> y;
		  ds.Union(x, y);
		}
	}
	for (int i=1; i<=N; i++) if (ds.Find(1) == ds.Find(i)) people.pb(i);
	cout << people.size() << "\n";
	for (size_t i=0; i<people.size(); i++) cout << people[i] << " ";
	return 0;
}