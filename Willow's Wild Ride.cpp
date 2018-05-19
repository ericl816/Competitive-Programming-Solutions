// #include <bits/stdc++.h>
#include "/Users/ericliu/Desktop/Competitive-Programming-Templates/stdc++.h"
#define ll long long
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define MAXN 200010
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

int T, N, lst;
char op;

void Do_Test_Cases () {
	int TEST_CASES = 10;
	while (TEST_CASES--) {
		cin >> T >> N;
		lst = 0;
		for (int i=1; i<=N; i++) {
			cin >> op;
			if (op == 'B') {
				if (i > lst) lst = i + T - 1;
				else lst += T;
			}
		}
		cout << (max(0, lst - N)) << "\n";
	}
}

int main () {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cout.tie(0);
    freopen("DATA11.txt", "r", stdin);
    Do_Test_Cases();
    return 0;
}