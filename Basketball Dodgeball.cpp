#include <bits/stdc++.h>
#define ll long long
#define MAXN 3010
#define INF 0x3f3f3f3f
#define vi vector<int>
#define pii pair<int, int>
#define pdd pair<double, double>
#define mp make_pair
#define pb push_back
#define f first
#define s second
using namespace std;

struct Edge {
  double x, y, r;
};

int N, M, baller1, baller2, src1, src2;
int dist[MAXN], dist1, dist2;
double temp1 = -INF, temp2 = -INF;
vi adj1[MAXN], adj2[MAXN];
queue<int> q;
bool vis[MAXN];
Edge arr1[MAXN], arr2[MAXN];

inline double Distance(Edge arr1, Edge arr2) {
	return (double) sqrt(pow((arr2.y - arr1.y), 2) + pow((arr2.x - arr1.x), 2));
}

void Dijkstras(vi vec[MAXN], int src) {
	vis[src] = 1;
	dist[src] = 0;
	q.push(src);
	while (!q.empty()) {
		int curr = q.front(); q.pop();
		for (int &next : vec[curr]) {
			if (!vis[next]) {
			  dist[next] = dist[curr] + 1;
				vis[next] = 1;
				q.push(next);
			}
		}
	}
}

int main () {
	scanf("%d %d", &N, &M);
	for (int i=0; i<N; i++) {
	  double X, Y, R;
		scanf("%lf %lf %lf", &X, &Y, &R);
		arr1[i].x = X;
		arr1[i].y = Y;
		arr1[i].r = R;
		if (arr1[i].r == 9001) baller1 = i;
		if (temp1 < arr1[i].y) {
		 	temp1 = arr1[i].y;
		 	src1 = i;
		}
	}
	for (int i=0; i<M; i++) {
	  double X, Y, R;
		scanf("%lf %lf %lf", &X, &Y, &R);
		arr2[i].x = X;
		arr2[i].y = Y;
		arr2[i].r = R;
		if (arr2[i].r == 9001) baller2 = i;
		if (temp2 < arr2[i].y) {
			temp2 = arr2[i].y;
			src2 = i;
		}
	}
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			if (arr1[i].r >= Distance(arr1[i], arr1[j])) adj1[i].pb(j);
		}	
	}
	for (int i=0; i<M; i++) {
		for (int j=0; j<M; j++) {
			if (arr2[i].r >= Distance(arr2[i], arr2[j])) adj2[i].pb(j);
		}
	}
	memset(dist, INF, sizeof(dist));
	memset(vis, 0, sizeof(vis));
	Dijkstras(adj1, src1);
	dist1 = dist[baller1];
	memset(dist, INF, sizeof(dist));
	memset(vis, 0, sizeof(vis));
	Dijkstras(adj2, src2);
	dist2 = dist[baller2];
	if (dist1 > dist2) printf("%s\n", ":'(");
	else if (dist1 < dist2) printf("%s\n", "We are the champions!");
	else printf("%s\n", "SUDDEN DEATH");
	return 0;
}
