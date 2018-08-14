#include <bits/stdc++.h>
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

int N, X, Y, Z;
string s;
char op;

void Do_Test_Cases () {
	int TEST_CASES = 10;
	while (TEST_CASES--) {
		vector<string> keys, check, check1;
		vi failed;
		bool flag = 1;
		cin >> N >> X >> Y >> Z;
		for (int i=0; i<N; i++) {
			cin >> s;
			check.pb(s);
		}
		cin >> op;
		for (int i=0; i<N; i++) {
			cin >> s;
			keys.pb(s);
		}
		cin >> op;
		for (string i : check) {
			string temp = "";
			for (size_t j=0; j<i.size(); j++) {
				int curr = (int) i[j] - '0';
				if (curr != 0) {
	  				if (curr & 1) {
	  					int next = curr - Y;
	  					if (next < 0) next = 0; // Cannot decrease below 0
	  					temp += to_string(next);
	  				}
	  				else if (!(curr & 1)) {
	  					int next = curr + X;
	  					temp += to_string(next);
	  				}
				}
				else temp += to_string(Z);
			}
			// cout << temp << "\n";
			check1.pb(temp);
		}
		for (int i=0; i<N; i++) {
			string a = check1[i];
			string b = keys[i];
			if (a != b) {
				failed.pb(i + 1);
				flag = 0;
			}
		}
		if (flag) cout << "MATCH" << "\n";
		else {
			cout << "FAIL: ";
			for (int i : failed) {
				cout << i;
				if (i != failed[failed.size() - 1]) cout << ",";
			}
			cout << "\n";
		}
	}
}

int main () {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cout.tie(0);
    // freopen("DATA31.txt", "r", stdin);
    Do_Test_Cases();
    return 0;
}