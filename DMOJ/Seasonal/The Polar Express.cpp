#include <bits/stdc++.h>
#define scan(y) do{while((y=getchar())<'0'); for(y-='0'; '0'<=(_=getchar()); y=(y<<3)+(y<<1)+_-'0');}while(0)
char _;
#define ll long long
#define ull unsigned long long
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

ll L, R;
set<string> S;
vector<ull> v;

inline string Calc (string n) {
	ll sum = 0;
	for (int i=0; i<n.size(); i++) sum += (int) n[i] - '0';
	return to_string(sum);
}

int main () {
    scan(L); scan(R);
    for (ll i=L; i<=R; i++) S.insert(Calc(to_string(i)));
    printf("%llu\n", S.size());
    return 0;
}