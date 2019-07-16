#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXM 1000000010
#define MAXN 1010
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

int N;
double x[MAXN], y[MAXN], sum, ans;

inline double Calc (double x, double y) {
  return abs(x - y) * abs(x - y);
}

int main () {
	scanf("%d", &N);
	for (int i=0; i<N; i++) scanf("%lf", &x[i]);
	for (int i=0; i<N; i++) scanf("%lf", &y[i]);
	for (int i=0; i<N; i++) sum += Calc(x[i], y[i]);
	printf("%.7f\n", sqrt(sum));
	return 0;
}