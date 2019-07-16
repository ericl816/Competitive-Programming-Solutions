#include<iostream>
#include<cstring>
#define min(a,b) ((a) > (b) ? (b) : (a))
using namespace std;

int dp [1001][1001];
char ch1 [1001];
char ch2 [1001];
int d, i, r;
string a, b;

void solve (int a, int b) {
	  for(int j=0; j<=a; j++) {
			for(int k=0; k<=b; k++) {
				if (j == 0) dp[j][k] = k * i;
				else if (k == 0) dp[j][k] = j * d;
				else if (ch1[j-1] == ch2[k - 1]) dp[j][k] = dp[j - 1][k - 1];
				else dp[j][k] = min(min(dp[j][k - 1] + i, dp[j - 1][k - 1] + r), dp[j - 1][k] + d);
			}
		}
	}
	
	int main () {
	  cin >> d >> i >> r;
	  cin >> a >> b;
	  strcpy (ch1, a.c_str());
	  strcpy (ch2, b.c_str());
	  int len1 = a.length();
	  int len2 = b.length();
	  solve(len1, len2);
	  printf("%d\n", dp[len1][len2]);
	}
