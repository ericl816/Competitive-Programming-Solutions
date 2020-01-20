#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXN 15
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

int arr[MAXN];

int main () {
	scan(arr[0]); scan(arr[1]); scan(arr[2]); scan(arr[3]);
	printf("%d %d %d %d %d\n", 0, arr[0], arr[0] + arr[1], arr[0] + arr[1] + arr[2], arr[0] + arr[1] + arr[2] + arr[3]);
	printf("%d %d %d %d %d\n", arr[0], 0, arr[1], arr[1] + arr[2], arr[1] + arr[2] + arr[3]);
	printf("%d %d %d %d %d\n", arr[0] + arr[1], arr[1], 0, arr[2], arr[2] + arr[3]);
	printf("%d %d %d %d %d\n", arr[0] + arr[1] + arr[2], arr[1] + arr[2], arr[2], 0, arr[3]);
	printf("%d %d %d %d %d\n", arr[0] + arr[1] + arr[2] + arr[3], arr[1] + arr[2] + arr[3], arr[2] + arr[3], arr[3], 0);
	return 0;
}