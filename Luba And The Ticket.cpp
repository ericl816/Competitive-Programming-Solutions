#include <bits/stdc++.h>
#define ll long long
using namespace std;

string s;
int sum, sum1, num;
vector<int> A, B, C;

int main () {
	cin >> s;
	for (int i=0; i<s.length(); i++) {
	  if (i < 3) {
			A.push_back(s[i] - '0');
			sum += s[i] - '0';
		}
		else if (i >= 3) {
			B.push_back(s[i] - '0');
			sum1 += s[i] - '0';
	  }
  }
		if (sum == sum1) cout << 0 << "\n";
		else {
			if (sum > sum1) {
				swap(A, B);
				swap(sum, sum1);
			}
			for (int i : A) C.push_back(9 - i);
			for (int i : B) C.push_back(i);
			sort(C.begin(), C.end(), greater<int>());
			for (int i=0; i<C.size() && sum < sum1; i++) {
				num++;
				sum += C[i];
		  }
		cout << num << "\n";
	}
}