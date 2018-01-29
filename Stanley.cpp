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

int A, B, cnt1, cnt2;
bool flag;

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int test = 7;
	while (test--) {
		cin >> A >> B;
		if (A > B) cnt1++;
		else if (B > A) cnt2++;
		if (cnt1 == 4 || cnt2 == 4) goto outer;
	}
	outer:
	cout << cnt1 << " " << cnt2 << endl;
	return 0;	
}