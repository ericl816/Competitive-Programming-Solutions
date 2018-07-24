#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXM 20
#define MAXN 1010
#define INF 0x3f3f3f3f
#define EPS 1e-10
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

int D, E;
double H, dam, curr_dam;
int T[MAXN], L[MAXN];
double A[MAXM], S[MAXM], X[MAXN];
vi start[MAXN], endd[MAXN];
bool flag;

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> H >> D >> E;
	for (int i=0; i<D; i++) {
		cin >> A[i] >> S[i];
		A[i] /= 100.0;
	}
	for (int i=0; i<E; i++) {
		cin >> T[i] >> L[i] >> X[i];
		start[T[i]].pb(i);
		endd[T[i] + L[i]].pb(i);
	}
	for (int i=0; i<MAXN; i++) {
		for (size_t j=0; j<start[i].size(); j++) {
			int &next = start[i][j];
			curr_dam += X[next];
		}
		for (size_t j=0; j<endd[i].size(); j++) {
			int &next = endd[i][j];
			curr_dam -= X[next];
		}
		dam = curr_dam;
		for (int j=0; j<D; j++) dam = min(dam, (1.0 - A[j]) * (max(0.0, (curr_dam - S[j]))));
		H -= dam;
		if (H <= EPS) {
			flag = 1;
			break;
		}
	}
	if (flag) cout << "DO A BARREL ROLL!" << "\n";
	else cout << fixed << setprecision(2) << H << "\n";
	return 0;
}