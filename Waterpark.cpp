#include<bits/stdc++.h>
using namespace std;

int n;
int x = 1;
int y = 1;
vector<int> v,w;
vector<int> G[10000];
int DP[10000];

int f(int a) {
	if(a == n) {
		DP[n] = 1;
		return 1;
	}
	else {
		int z = 0;
		for(int i=0; i<G[a].size(); i++) {
			if(DP[G[a][i]] == -1) {
				DP[G[a][i]] = f(G[a][i]);
				z = z + DP[G[a][i]]; 
			}
			else z = z + DP[G[a][i]];
		}
		return z;	
	}
}

int main() {
    ios::sync_with_stdio(0);
	cin >> n;
	while(x != 0 && y != 0) {
		cin >> x >> y;
		G[x].push_back(y);
	}
	for(int i=0; i<10000; i++) DP[i] = -1;
	cout << f(1) << endl;
}
