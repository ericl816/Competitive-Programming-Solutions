#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXN 110
#define INF 0x3f3f3f3f
#define min(a, b) (a) < (b) ? (a) : (b)
#define max(a, b) (a) < (b) ? (b) : (a)
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define mii map<int, int>
#define umii unordered_map<int, int>
using namespace std;

int N;
vector<string> vec;
string s;

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	vec.pb("Mind");
	vec.pb("Power");
	vec.pb("Reality");
	vec.pb("Soul");
	vec.pb("Space");
	vec.pb("Time");
	while (N--) {
		cin >> s;
		vec.erase(std::remove(vec.begin(), vec.end(), s), vec.end());
	}
	for (string s : vec) cout << s << "\n";
	return 0;
}