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

// This method helps trim the input
void Trim_Input () {
	ch = line[idx++];
	while (isspace(ch)) ch = line[idx++];
}

// This method builds the Binary Tree by being called on recursively for the left and right children
void Build_Tree (int node) {
	// while (line[idx] == ' ' || line[idx] == ')') idx++;
	Trim_Input();
	if (ch == '(') {
		Build_Tree(node << 1);
		Build_Tree(node << 1 | 1);
		Trim_Input();
	}
	else if (ch >= '0' && ch <= '9') {
		int res = ch - '0';
		ch = line[idx++];
		while (ch >= '0' && ch <= '9') { // If the number is at least 2 digits long
			res *= 10;
			res += ch - '0';
			ch = line[idx++];
		}
		--idx;
		tree[node] = res;
	}
}

// Perform Knapsack DP on the tree using DFS
void DFS (int node) {
	if (tree[node] == 0) { // If it's a leaf node
		DFS(node << 1);
		DFS(node << 1 | 1);
		// Do Knapsack DP on left subtree
		for (int i=0; i<=X; i++) {
			for (int j=0; j<=i; j++) {
				LeftDP[node][i] = max(LeftDP[node][i], min(DP[node << 1][i - j], (1 + j) * (1 + j)));
			}
		}
		// Do Knapsack DP on right subtree
		for (int i=0; i<=X; i++) {
			for (int j=0; j<=i; j++) {
				RightDP[node][i] = max(RightDP[node][i], min(DP[node << 1 | 1][i - j], (1 + j) * (1 + j)));
			}
		}
		// Do Knapsack DP on left and right subtrees
		for (int i=0; i<=X; i++) {
			for (int j=0; j<=i; j++) {
				DP[node][i] = max(DP[node][i], LeftDP[node][i - j] + RightDP[node][j]);
			}
		}
	}
	// Else if we're dealing with children node
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