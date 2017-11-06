#include <bits/stdc++.h>
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

int N, x, minn = -1, maxx = -1;
umii freq;


int main () {
	scanf("%d", &N);
	for (int i=0; i<N; i++) {
		scanf("%d", &x);
		freq[x]++;
	}
	for (int i=0; i<=100; i++) {
		if (freq[i] ^ 0) {
			if (minn == -1 || freq[i] < freq[minn]) minn = i;
			if (maxx == -1 || freq[i] >= freq[maxx]) maxx = i;
		}
	}
	printf("%d\n", abs(maxx - minn));
	return 0;
}