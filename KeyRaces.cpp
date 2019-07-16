#include <bits/stdc++.h>
#define ll long long 
using namespace std;

const int MAXN = 1e6 + 10;
int s, v1, v2, t1, t2, time1, time2;

int main() {
	cin >> s >> v1 >> v2 >> t1 >> t2;
	time1 = t1 * 2 + s * v1;
	time2 = t2 * 2 + s * v2;
	if (time1 == time2) cout << "Friendship" << "\n";
	else if (time1 < time2) cout << "First" << "\n";
	else cout << "Second" << "\n";
}