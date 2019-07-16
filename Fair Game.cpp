#include <bits/stdc++.h>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <stack>
#define ll long long
#define MAXN 110
#define INF 0x3f3f3f3f
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define umii unordered_map<int, int>
#define mii map<int, int>
#define si set<int>
#define it iterator
using namespace std;

int N, arr[MAXN];
bool flag;
mii players;

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i=0; i<N; i++) {
		cin >> arr[i];
		players[arr[i]]++;
	}
	if (players.size() == 2 && players.begin()->s == (++players.begin())->s) {
		printf("%s\n", "YES");
		printf("%d %d\n", players.begin()->f, (++players.begin())->f);
		flag = 1;
		return 0;
	}
	if (!flag) printf("%s\n", "NO");
	return 0;
}