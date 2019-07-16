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

int N, M, A, B, cnt;
vi mst;

struct Disjoint {
private:
	int N;
	vi lead, rank;

public:
	Disjoint(int N) : N(N), lead(N + 1), rank(N + 1) { }

	void make_Set () {
		for (int i=1; i<=N; i++) lead[i] = i;
	}
	
	int Find (int x) {
		while (lead[x] ^ x) {
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
		if (Merge(x, y)) {
			if (rank[c] > rank[d]) {
			  lead[d] = c;
			  rank[c] += rank[d];
			}
			else {
				lead[c] = d;
				rank[d] += rank[c];
			}
		}
	}
}; 

Disjoint ds(MAXN);

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	ds.make_Set();
	for (int i=1; i<=M; i++) {
		cin >> A >> B;
		if (ds.Merge(A, B)) {
			cnt++;
			ds.Union(ds.Find(A), ds.Find(B));
			mst.pb(i);
		}
	}
	if (cnt ^ N - 1) {
	  cout << "Disconnected Graph" << "\n";
	  return 0;
	}
	for (auto i : mst) cout << i << "\n";
	return 0;	
}