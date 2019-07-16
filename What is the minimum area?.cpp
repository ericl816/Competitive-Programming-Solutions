#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define INF 0x3f3f3f3f
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define umii unordered_map<int, int>
#define mii map<int, int>
using namespace std;

int N, x, y, minside = 1e6;
vector<pii> coor;

int main () {
	cin >> N;
	for (int i=0; i<N; i++) {
		cin >> x >> y;
		coor.pb(mp(x, y));
	}
	for (int i=0; i<N; i++)
	  for (int j=i+1; j<N; j++) 
	    minside = min(minside, max(abs(coor[i].f - coor[j].f), abs(coor[i].s - coor[j].s)));
	cout << (minside * minside) << endl;
	return 0;
}