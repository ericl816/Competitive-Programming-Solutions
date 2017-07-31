#include <bits/stdc++.h>
#define ll long long 
using namespace std;

const int MAXN = 1e6 + 10;
int n, k, cnt[MAXN], num;
bool doors[26], flag;
char ch[MAXN];

int main() {
	scanf("%d %d", &n, &k);
	scanf("%s", ch + 1);
	memset(doors, 0, sizeof(doors));
	for (int i=1; i<=n; i++) 
	  if (!doors[ch[i] - 'A']) {
	    doors[ch[i] - 'A'] = 1;
	    cnt[i]++;
	  }
	 memset(doors, 0, sizeof(doors));
	for (int i=n; i>=1; i--) 
	  if (!doors[ch[i] - 'A']) {
	    doors[ch[i] - 'A'] = 1;
	    cnt[i + 1]--;
	  }
	for (int i=1; i<=n; i++) {
	  num += cnt[i];
	  if (num > k) { 
	    printf("%s\n", "YES"); 
	    flag = 1;
	    return 0; 
	  }
	}
	if (!flag) printf("%s\n", "NO");
}