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

ll logN;
long double N, val;
vector<ll> vec;

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	logN = floor(log2(N));
	for (int i=0; i<logN; i++) {
		vec.pb(pow(2, i));
		val += pow(2, i);
	}
	vec.pb(N - val);
	cout << logN + 1 << endl;
	for (size_t i=0; i<vec.size(); i++) cout << vec[i] << " " ;
	return 0;
}