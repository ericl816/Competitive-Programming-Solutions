#include <bits/stdc++.h>
#define ll long long 
#define MAXN 40
#define INF 0x3f3f3f3f
#define mp make_pair
#define pii pair<int, int>
#define vi vector<int>
#define f first
#define s second
#define min(a, b) (a) < (b) ? (b) : (a)
#define max(a, b) (a) < (b) ? (b) : (a)
using namespace std;

int N;
int temp[] = {-1, -1, -1, 0};
int temp1[] = {-1, 0, 1, -1};
bool flag;
char ch[MAXN][MAXN];

inline bool recur (int a, int b, int c, int d, int e, char ch1) {
  if (a >= N || a < 0 || b >= N || b < 0 || ch[a][b] ^ ch1) return 0;
  else if (e == 0) return 1;
  return recur(a + c, b + d, c, d, e - 1, ch1);
}

int main () {
	cin >> N;
	for (int i=0; i<N; i++) { 
		for (int j=0; j<N; j++) { 
			cin >> ch[i][j];
			if (ch[i][j] == '.') continue;
			for (int k=0; k<4; k++) {
			  if (recur(temp[k] + i, temp1[k] + j, temp[k], temp1[k], 1, ch[i][j])) {
			    printf("%c\n", ch[i][j]);
			    flag = 1;
			    return 0;
			  }
			}
		}	
  }
  if (!flag) printf("%s\n", "ongoing");
  return 0;
}
