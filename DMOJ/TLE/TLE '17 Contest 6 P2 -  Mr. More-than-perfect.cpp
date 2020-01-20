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

int N, idx, numerator, denominator;
string frac, name, input, num, denom, suffix; 
bool flag, validfrac, validname;

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> name;
	getline(cin, input);
	while (N--) {
		num = "", denom = "", suffix = "";
		flag = 0;
		getline(cin, input);
		idx = 0;
		while (idx < input.size() && input[idx] != '/') {
			num += input[idx];
			idx++;
		}
		idx++;
		while (idx < input.size() && input[idx] != ' ') {
			denom += input[idx];
			idx++;
		}
		idx++;
		while (idx < input.size()) {
			suffix += input[idx];
			idx++;
		}
		if (denom == "") flag = 1;
		else {
			numerator = stoi(num.c_str());
			denominator = stoi(denom.c_str());
			validfrac, validname = 1;
			if ((static_cast<double>(numerator) / denominator) > 1) validfrac = 1;
			else validfrac = 0;
			if (name.size() < suffix.size()) validname = 0;
			else {
				for (int i=0; i<suffix.size(); i++) {
					if (suffix[i] != name[i]) {
						validname = 0;
						break;
					}
				}
			}
			flag = validfrac && validname;
		}
		cout << (flag ? "Y" : "N") << endl;
	}
	return 0;
}