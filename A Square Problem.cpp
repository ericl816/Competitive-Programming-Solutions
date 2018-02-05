#include <bits/stdc++.h>
#define ll long long
#define MAXN 40
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
char grid[MAXN][MAXN];
int arr[MAXN][MAXN];
string s;
vi row, col;
bool latin, reduced;

int val (char c) {
    if (c >= '0' && c <= '9') return (int) c - '0';
    else return (int) c - 'A' + 10;
}

bool CheckDuplicates () {
  for (int i=0; i<N; i++) {
    for (int j=0; j<N; j++) {
      int next = arr[i][j];
      for (int k=j + 1; k<N; k++) {
        if (next == arr[i][k]) return 1;
      }
    }
  }
  return 0;
} 

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i=0; i<N; i++) {
		cin >> s;
		for (int j=0; j<N; j++) arr[i][j] = val(s[j]);
  }
	for (int i=0; i<N; i++) {
		row.pb(arr[0][i]);
		col.pb(arr[i][0]);
	}
	if (!CheckDuplicates()) latin = 1;
	if (is_sorted(row.begin(), row.end()) && is_sorted(col.begin(), col.end())) reduced = 1;
  if (!latin) cout << "No" << endl; 
  else if (latin && !reduced) cout << "Latin" << endl;
  else if (latin && reduced) cout << "Reduced" << endl;
	return 0;	
}