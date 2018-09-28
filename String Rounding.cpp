#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
using namespace std;

string s, ans;
bool flag;

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> s;
	int size = s.length();
	if (s[size - 1] >= 'a' && s[size - 1] <= 'm') s[size - 1] = 'a';
	else if (s[size - 1] >= 'n' && s[size - 1] <= 'z') {
	  s[size - 1] = 'a';
	  if (s[size - 2] != 'z') { //Increment next char by 1
	  	if (s[size - 2] != '\0') s[size - 2]++;
	  	else if (s[size - 2] == '\0') {
	  		flag = 1;
	  		ans += 'a' + s;
	      }
	  }
	  else { //Round again
	    for (int i=2; i<=100; i++) {
	      	if (s[size - i] >= 'a' && s[size - i] <= 'm') {
		        s[size - i] = 'a';
		        break;
	      	}
	      	else if (s[size - i] >= 'n' && s[size - i] <= 'z') {
	      		s[size - i] = 'a';
	      		if (s[size - i - 1] != 'z') {
	      			if (s[size - i - 1] != '\0') {
		      	    s[size - i - 1]++;
		      	    break;
		      	  }
	  	      	else if (s[size - i - 1] == '\0') flag = 1;
		      	}
	      	}
	    }
	  }
	}
	if (flag) ans = 'a' + s;
	else if (!flag) ans += s;
	cout << ans;
	return 0;
}