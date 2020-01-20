#include <bits/stdc++.h>
#define ll long long
#define MAXN 100010
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define mii map<int, int>
#define umii unordered_map<int, int>
using namespace std;

string s;
int Q, a, b;
int psa[MAXN];

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> s;
	for (int i=0; i<s.size(); i++) psa[i] = psa[i - 1] + (s[i] == 'G');
	cin >> Q;
	for (int i=0; i<Q; i++) {
		cin >> a >> b;
		cout << psa[b] - psa[a - 1] << endl;
	}
	return 0;
}