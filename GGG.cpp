#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, val, lo, mid, hi, len;
    len = 0;
    int dp [1000001]; 
    unordered_map <int, int> hm;
    vector <int> al;
    scanf("%d", &n);
    int a;
    for (int i=0; i<n; i++)
     scanf("%d", &a), hm[a] = i;
    int m;
    scanf("%d", &m);
    for (int i=0; i<m; ++i){
      scanf("%d", &val);
      if (hm.count(val))
      al.push_back(hm[val]);
    }
for (int i=0; i<al.size(); ++i){
    lo = 1;
    hi = len;
    while (lo <= hi){
    mid = lo + hi >> 1;
	if (al[dp[mid]] >= al[i])
	hi = mid - 1;
	else
	lo = mid + 1;	
}
            dp[lo] = i;
            len = max(len, lo);
}
printf("%d\n", len);
}
