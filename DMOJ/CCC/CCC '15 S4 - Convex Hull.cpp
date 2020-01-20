// ConsoleApplication13.cpp : This file contains the 'main' function. Program execution begins and ends there.
// DEBUG

 
#include <iostream>
#include <bits/stdc++.h>



using namespace std; 


struct route {
	int u;
	int v;
	int w;
	int z;
};

struct CompareRoute {
	bool operator()(route r1, route r2)
	{
		if (r1.w > r2.w)
			return true;
		else if (r2.w > r1.w)
		{
			return false;
		}
		else
		{
			if (r1.z > r2.z)
				return true;
			else if (r2.z > r1.z)
				return false;
			else
				return true;
		}
	}
};




int K, N, M,A,B,dis[2001][201];
vector<route> adj[2001];
bool vis[2001][201];

int hull[2001];
priority_queue<route,vector<route>,CompareRoute> pq;

int main()
{
	memset(dis, 0x3f3f3f3f, sizeof(dis));
	memset(hull, 0x3f3f3f3f, sizeof(hull));
	cin >> K >> N >> M;
	while (M--)
	{
		int u, v, w, z;
		cin >> u >> v >> w >> z;
		route tmp = {u,v,w,z};
		adj[u].push_back(tmp);
		tmp = { v,u,w,z };
		adj[v].push_back(tmp);
	}

	cin >> A >> B;

	
	//dijakstra

	for (int i = 0; i < K; i++)
		dis[A][i] = 0;
	route tmp = {A,A,0,0};
	pq.push(tmp);
	while (!pq.empty())
	{
		auto top = pq.top();
		pq.pop();
		if (vis[top.v][top.z])
			continue;
		vis[top.v][top.z] = 1;
		for (auto x : adj[top.v])
		{
			for (int i = 0; i + x.z < K; i++)
			{
			    if (dis[x.v][i + x.z] > dis[x.u][i] + x.w) {
			        dis[x.v][i + x.z] = dis[x.u][i] + x.w;
			        route tmp = {x.u, x.v, dis[x.v][i + x.z], i + x.z};
			        pq.push(tmp);
			    }
			}
		}
	}
	int output = 0x3f3f3f3f;
	for (int i = 0; i < K; i++)
		output = min(output, dis[B][i]);
	if (output < 0x3f3f3f3f)
		cout << output;
	else
		cout << -1;
	
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file