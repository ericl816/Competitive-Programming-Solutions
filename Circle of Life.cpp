#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[100010], b[100010];
string ch;
ll N, T, i, j, temp;

int main() {
  cin >> N >> T >> ch;
	for (int i=0; i<N; i++) a[i] = ch[i] - '0';
	for(int i=59; i>=0; i--) {
		if((T >> i) & 1) {
			temp = (1ll << i) % N;
			for(int j=0; j<N; j++) b[j] = a[(j - temp + N) % N] ^ a[(j + temp) % N];
			memcpy(a, b, sizeof a);
		}
	}
	for(int i=0; i<N; i++) cout << a[i];
}
