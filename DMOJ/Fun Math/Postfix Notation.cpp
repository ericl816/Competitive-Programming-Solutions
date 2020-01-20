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

stack<double> st;
double a, b;
int c, d;
string s, buff;

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	getline(cin, s);
	istringstream iss(s);
	while (getline(iss, buff, ' ')) {
		if (buff == "+") {
			a = st.top(); st.pop();
			b = st.top(); st.pop();
			st.push(a + b);
		}
		else if (buff == "-") {
			a = st.top(); st.pop();
			b = st.top(); st.pop();
			st.push(b - a);
		}
		else if (buff == "*") {
			a = st.top(); st.pop();
			b = st.top(); st.pop();
			st.push(a * b);
		}
		else if (buff == "/") {
			a = st.top(); st.pop();
			b = st.top(); st.pop();
			st.push(b / a);
		}
		else if (buff == "%") {
			c = (int) st.top(); st.pop();
			d = (int) st.top(); st.pop();
			st.push(d % c);
		}
		else if (buff == "^") {
			a = st.top(); st.pop();
			b = st.top(); st.pop();
			st.push(pow(b, a));
		}
		else st.push(atof(buff.c_str()));
	}
	return !printf("%.1lf\n", st.top());
}