#include <bits/stdc++.h>
#define ll long long
#define MAXN 30
#define INF 0x3f3f3f3f
#define min(a, b) (a) < (b) ? (a) : (b)
#define max(a, b) (a) < (b) ? (b) : (a)
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define umsi unordered_map<string, int>
#define msi map<string, int>
using namespace std;

struct Edge {
	string src, dest;
	int cost;
};

int N, price;
string CODE1, CODE2;

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	for (int i=0; i<5; i++) {
	  msi airports;
	  vector<Edge> adj;
		cin >> N;
		for (int j=0; j<N; j++) {
			cin >> CODE1 >> CODE2 >> price;
			adj.pb((Edge) {CODE1, CODE2, price});
			airports[CODE1] = airports[CODE2] = INF;
		}
		airports["YYZ"] = 0;
		for (int k=0; k<airports.size(); k++) {
			for (Edge &next : adj) {
				int nextcost = airports[next.src] + next.cost;
				airports[next.dest] = min(nextcost, airports[next.dest]);
			}
		}
		cout << (airports["SEA"]) << "\n";
	}	
	return 0;
}