#include <bits/stdc++.h>
#define ll long long
#define MAXN 10010
#define min(a, b) (a) < (b) ? (a) : (b)
#define max(a, b) (a) < (b) ? (b) : (a)
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define mii map<int, int>
#define umii unordered_map<int, int>
#define msi map<string, int>
#define umsi unordered_map<string, int>
using namespace std;

struct BIT {
private:
	int N;
	vi tree;

public:
	BIT (int N) : N(N), tree(N + 1) { }

	void Update (int idx, int val) {
		for (; idx<=N; idx += idx & -idx) tree[idx] += val;
	}

	ll Query (int idx) {
		ll sum = 0;
		for (; idx; idx -= idx & -idx) sum += tree[idx];
		return sum;
	}

	ll Query (int x, int y) {
		return Query(y) - Query(x - 1);
	}
};

int C, cnt = 1;
char op;
string R, X, Y;
umsi rocks;
BIT tree(MAXN);

inline ll CalcMass (string s) {
	ll mass = 0;
	for (int i=0; i<s.size(); i++) mass += s[i] - 'a' + 1; // Since 'a' = 1 not 0
	return mass;
}

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> C;
	for (int i=0; i<C; i++) {
		cin >> op;
		if (op == 'A') {
			cin >> R;
			if (rocks.count(R)) cout << "Can't add " << R << endl;
			else {
				rocks[R] = cnt;
				tree.Update(cnt, CalcMass(R));
				cnt++;
			}
		}
		else if (op == 'S') {
			cin >> X >> Y;
			int pos1 = rocks[X];
			int pos2 = rocks[Y];
			rocks[X] = pos2;
			rocks[Y] = pos1;
			tree.Update(pos1, CalcMass(Y) - CalcMass(X));
			tree.Update(pos2, CalcMass(X) - CalcMass(Y));
			//tree.Update(pos1, CalcMass(Y));
			//tree.Update(pos2, CalcMass(X));
		}
		else if (op == 'M') {
			cin >> X >> Y;
			int pos1 = rocks[X];
			int pos2 = rocks[Y];
			cout << tree.Query(min(pos1, pos2), max(pos1, pos2)) << endl;
		}
		else if (op == 'R') {
			cin >> X >> Y;
			int pos = rocks[X];
			rocks.erase(X);
			rocks[Y] = pos;
			tree.Update(pos, -CalcMass(X));
			tree.Update(pos, CalcMass(Y));
		}
		else if (op == 'N') cout << cnt - 1 << endl;
		else i--;
	}
	return 0;
}