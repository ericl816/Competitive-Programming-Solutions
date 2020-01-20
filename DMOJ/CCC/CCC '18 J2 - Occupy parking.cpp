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

int N, cnt;
string s1, s2;

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> s1 >> s2;
	for (int i=0; i<N; i++) if (s1[i] == 'C' && s2[i] == 'C') cnt++;
	cout << cnt << endl;
	return 0;
}