#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
using namespace std;

int N;

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	if (N < 2) {
	    cout << "not" << "\n";
	    return 0;
	}
	else {
		for (int i=2; i<N; i++) 
		    if (!(N % i)) {
    		    cout << "not" << "\n";
    		    return 0;
		    }
		cout << "prime" << "\n";
	}
	return 0;
}