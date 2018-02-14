#include <bits/stdc++.h>
#define ll long long
#define MAXN 35
#define INF 0x3f3f3f3f
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

int N, K;
bool flag1, flag2, flag3 = 1, flag4 = 1;

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i=0; i<N; i++) {
		cin >> K;
		K /= 1000;
		if (K > 10) flag1 = 1;
		if (K > 1) flag2 = 1;
		flag4 &= K <= 10;
		flag3 &= K <= 1;
	}
	if (flag1) {
		cout << "Something is wrong with these cuteness values" << endl;
		return 0;
	}
	else if (flag2 && flag4) {
		cout << "Cuteness by definition is similarity to Cactus" << endl;
		return 0;
	}
	else if (flag3) {
		cout << "Cuteness by definition is similarity to Carol" << endl;
		return 0;
	}
	return 0;
}