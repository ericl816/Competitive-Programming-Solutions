#include <bits/stdc++.h>
#define ll long long
#define MAXM 2510
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

char ch;
string line;
int X, idx;
int tree[MAXN << 2];
int DP[MAXN << 2][MAXM], LeftDP[MAXN << 2][MAXM], RightDP[MAXN << 2][MAXM];

void Trim_Input () {
	ch = line[idx++];
	while (isspace(ch)) ch = line[idx++];
}

void Build_Tree (int node) {
	Trim_Input();
	if (ch == '(') {
		Build_Tree(node << 1);
		Build_Tree(node << 1 | 1);
		Trim_Input();
	}
	else if (ch >= '0' && ch <= '9') {
		int res = ch - '0';
		ch = line[idx++];
		while (ch >= '0' && ch <= '9') {
			res *= 10;
			res += ch - '0';
			ch = line[idx++];
		}
		--idx;
		tree[node] = res;
	}
}

void DFS (int node) {
	if (!tree[node]) {
		DFS(node << 1);
		DFS(node << 1 | 1);
		for (int i=0; i<=X; i++) {
			for (int j=0; j<=i; j++) {
				LeftDP[node][i] = max(LeftDP[node][i], min(DP[node << 1][i - j], (1 + j) * (1 + j)));
			}
		}
		for (int i=0; i<=X; i++) {
			for (int j=0; j<=i; j++) {
				RightDP[node][i] = max(RightDP[node][i], min(DP[node << 1 | 1][i - j], (1 + j) * (1 + j)));
			}
		}
		for (int i=0; i<=X; i++) {
			for (int j=0; j<=i; j++) {
				DP[node][i] = max(DP[node][i], LeftDP[node][i - j] + RightDP[node][j]);
			}
		}
	}
	else for (int i=0; i<=X; i++) DP[node][i] = tree[node] + i;
}

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	getline(cin, line);
	cin >> X;
	Build_Tree(1);
	DFS(1);
	cout << DP[1][X] << endl;
	return 0;	
}