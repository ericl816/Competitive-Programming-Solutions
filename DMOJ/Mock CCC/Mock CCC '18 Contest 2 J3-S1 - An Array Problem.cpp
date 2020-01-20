#include <bits/stdc++.h>
#define ll long long
#define MAXN 55
#define INF 0x3f3f3f3f
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
ll sum, cnt;
ll a[MAXN];
int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i=0; i<N; i++) cin >> a[i];
	sort(a, a + N);
	for (int i=0; i<N - 1; i++) sum += a[i];
	if (sum < a[N - 1]) cout << sum << endl;
	else cout << ((sum + a[N - 1]) >> 1) << endl;
	return 0;	
}