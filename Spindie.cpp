#include <algorithm>
#include <vector>
#include <map>
#include <string.h>
#include <iostream>
#include <cstring>
#define ll long long
#define MAXN 1000010
#define vi vector<int>
using namespace std;

int test_cases = 10, N, S;
vi vec;
bool poss[MAXN], flag;

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	while (test_cases--) {
		cin >> N;
		vec.clear();
		memset(poss, 0, sizeof(poss));
		for (int i=0, x; i<N; i++) {
			cin >> x;
			vec.push_back(x);
		}
		for (int i=0; i<N; i++) {
			for (int j=0; j<N; j++) {
				poss[vec[i] + vec[j]] = 1;
				poss[vec[i] * vec[j]] = 1;
			}
		}
		for (int i=0; i<5; i++) {
			int tar;
			flag = 0;
			cin >> tar;
			for (int j=0; j<N; j++) {
				if ((tar - vec[j] >= 0 && poss[tar - vec[j]]) || (tar % vec[j] == 0 && poss[tar / vec[j]])) {
					flag = 1;
					break;
				}
			}
			if (flag) cout << "T";
			else cout << "F";
		}
		cout << "\n";
	}
	return 0;
}