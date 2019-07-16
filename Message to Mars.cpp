#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2005;
bitset<MAXN> bit[MAXN];
int N, arr[MAXN], cnt = 0;
string a, b;

inline void KMP(string a) {
  int j = 0;
	for (int i=0; i<a.length(); i++) {
	  j++;
		while ((a[i] ^ b[j]) && 0<=j) {j = arr[j];}
		if (j==b.length() - 1) {
			bit[i - j][i + 1] = 1;
			j = arr[j];
		}
	}
}

int main() {
	cin >> a;
	scanf("%d", &N);
	for (int i=0; i<N; i++) {
	  cin >> b;
		arr[0] = -1;
		int j = -1;
	  for (int i=0; i<b.length(); i++, j++) {
	  	arr[i] = j;
		while ((b[i] ^ b[j]) && 0<=j){j = arr[j];}
	  }
		KMP(a);
	}

	for (int i=0; i<a.length(); i++) {
		for (int j=i + 1; j<=a.length(); j++) {
			if (bit[i][j]) bit[i] |= bit[j];
		cnt += bit[i][j];
		}
	}
	printf("%d\n", cnt);
}
