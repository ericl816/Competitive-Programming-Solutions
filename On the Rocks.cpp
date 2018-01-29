#include <bits/stdc++.h>
#define ll long long
#define MAXN 10
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

int N, M, cnt1, cnt2, minn1 = INF, minn2 = INF, minn;
vi A, B;
bool flag1, flag2;

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	if (N == 0 && M == 0) {
		cout << "0 0" << endl;
		return 0;
	}
	for (int i=0, x; i<N; i++) {
		cin >> x;
		minn1 = min(minn1, x);
		A.pb(x);
	}
	for (int i=0, x; i<M; i++) {
		cin >> x;
		minn2 = min(minn2, x);
		B.pb(x);
	}
	minn = min(minn1, minn2);
	if (find(A.begin(), A.end(), minn) != A.end()) flag1 = 1;
	else if (find(B.begin(), B.end(), minn) != B.end()) flag2 = 1;
	
	if (flag1) {
		for (int i : A) {
		  if (i < minn2) cnt1++;
		}
	}
	else if (flag2) {
	  for (int i : B) {
		  if (i < minn1) cnt2++;
		}
	}
	cout << cnt1 << " " << cnt2 << endl;
	return 0;	
}