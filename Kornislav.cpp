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

int A, B, C, D;
vi vec;

int main () {
	scan(A); scan(B); scan(C); scan(D);
	vec.pb(A);
	vec.pb(B);
	vec.pb(C);
	vec.pb(D);
	sort(vec.begin(), vec.end());
	printf("%d\n", vec[0] * vec[2]);
	return 0;
}