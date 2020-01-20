#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define INF 0x3f3f3f3f
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
using namespace std;

int C, op;
string type;
set<bool> s;
vector<bool> vec;
bool flag;
priority_queue<bool, vector<bool>, greater<bool> > pq;

int main () {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> C;
	while (C--) {
		cin >> op;
		if (op == 1) {
			cin >> type;
			if (type[0] == 't') {
				flag = s.find(1) != s.end();
				cout << (flag ? "false" : "true") << "\n";
				s.insert(1);
				vec.pb(1);
			}
			else {
				flag = s.find(0) != s.end();
				cout << (flag ? "false" : "true") << "\n";
				s.insert(0);
				vec.pb(0);
			}
		}
		else if (op == 2) {
			cin >> type;
			if (type[0] == 't') {
				flag = s.find(1) != s.end();
				cout << (flag ? "true" : "false") << "\n";
				if (flag) {
					s.erase(1);
					vec.erase(remove(vec.begin(), vec.end(), 1), vec.end());
				}
			}
			else {
				flag = s.find(0) != s.end();
				cout << (flag ? "true" : "false") << "\n";
				if (flag) {
					s.erase(0);
					vec.erase(remove(vec.begin(), vec.end(), 0), vec.end());
				}
			}
		}
		else if (op == 3) {
			cin >> type;
			if (type[0] == 't') {
				if (s.find(1) == s.end()) cout << -1 << "\n";
				else cout << (lower_bound(vec.begin(), vec.end(), 1) - vec.begin()) << "\n";
			}
			else {
				if (s.find(0) == s.end()) cout << -1 << "\n";
				else cout << (lower_bound(vec.begin(), vec.end(), 0) - vec.begin()) << "\n";
			}
		}
		else {
			if (!s.empty()) for (auto i : s) pq.push(i);
			while (!pq.empty()) {
				bool curr = pq.top();
				pq.pop();
				cout << (curr ? "true" : "false") << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}