#include<iostream>
#define ull unsigned long long 
#define scan(x) do{while((_n=getchar_unlocked())<45);if(_n-45)x=_n;else x=getchar_unlocked();for(x-=48;47<(_=getchar_unlocked());x=(x<<3)+(x<<1)+_-48);if(_n<46)x=-x;}while(0)
char _, _n;

using namespace std;

int n, q, x, y, z, l, x1, y1, z1, x2, y2, z2;
char ch;
long BIT [251][251][251];

void update (int x, int y, int z, int val) {
  for (int i = x; i <= n; i += (i & -i)){
    for (int j=y; j <= n; j += (j & -j)){
      for (int k = z; k <= n; k += (k & -k)){
        BIT[i][j][k] += val;
      }
    }
  }
} 

long query (int x, int y, int z) {
  long ans = 0;
  for (int i = x; i > 0; i -= (i & -i)){
    for (int j = y; j > 0; j -= (j & -j)){
      for (int k = z; k > 0; k -= (k & -k)){
          ans += BIT[i][j][k];
      }
    }
  }
  return ans;
}

long query1 (int x1, int y1, int z1, int x2, int y2, int z2) {
  long area = (query(x2, y2, z2) - query(x1, y2, z2) - query(x2, y1, z2) - query(x2, y2, z1) + query(x1, y1, z2) + query(x2, y1, z1) + query(x1, y2, z1) - query(x1, y1, z1));
  return area;
}

int main () {
  scan(n); 
  scan(q);
  ull sum = 0;
  for (int i = 0; i < q; i++){
    scanf(" %c", &ch);
    if (ch == 'C'){
      scan(x); scan(y); scan(z); scan(l);
      update (x, y, z, l - query1 (x - 1, y - 1, z - 1, x, y, z));
    }
    else {
      scan(x1); scan(y1); scan(z1); scan(x2); scan(y2); scan(z2);
      int temp1 = x1 - 1, temp2 = y1 - 1, temp3 = z1 - 1;
      sum += query1 (temp1, temp2, temp3, x2, y2, z2);
    }
  }
  printf("%1lu\n", sum);
}
