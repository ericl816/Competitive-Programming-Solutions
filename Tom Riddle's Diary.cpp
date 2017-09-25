#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
using namespace std;

set<string> ss;
int n;
string s;

int main () {
    cin >> n;
    for (int i=0; i<n; i++) {
    	cin >> s;
    	if (ss.count(s)) cout << "YES" << "\n";
    	else {
    		cout << "NO" << "\n";
    		ss.insert(s);
    	}
    }
    return 0;
}