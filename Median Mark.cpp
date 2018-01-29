#include <bits/stdc++.h>
#define MAXN 2010
#define INF 0x3f3f3f3f
#define ll long long
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
int arr[1010];

int main () {
	scanf("%d", &N);
	for (int i=0; i<N; i++) {
		scanf("%d", arr + i);
	}
	int mid = N >> 1;
	sort(arr, arr + N);
	if (N & 1) printf("%d\n", round(arr[mid]));
	else printf("%d\n", (int) round((arr[mid - 1] + arr[mid]) / 2.0));
	return 0;
}