#include <bits/stdc++.h>
#define ll long long
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

int M, K, N, X;
double ans, avg;
bool flag;

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> M >> K >> N;
	for (int i=0; i<=M; i++) {
	  avg = 1.0 * (i + K) / N;
	  if (avg >= 0.595) {
	    flag = 1;
	    cout << i << endl;
	    return 0;
	    break;
	  }
	}
	cout << "have mercy snew" << endl;
	return 0;
}