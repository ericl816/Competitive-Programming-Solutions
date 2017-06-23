#include<iostream>
#define ull unsigned long long
#define min(a, b) ((a) < (b) ? (a) : (b))
#define scan(x) do{while((_n=getchar_unlocked())<45);if(_n-45)x=_n;else x=getchar_unlocked();for(x-=48;47<(_=getchar_unlocked());x=(x<<3)+(x<<1)+_-48);if(_n<46)x=-x;}while(0)
char _, _n;

using namespace std;

int BIT1 [500001];
int BIT2 [500001];
ull sum = 0;
int n, x;

void update (int i, int val, int BIT []) {
  for (; i < 500001; i += (i & -i))
        BIT[i] += val;
}

int query (int i, int BIT []) {
  int ans = 0;
  for (; i > 0; i -= (i & -i))
        ans += BIT[i];
  return ans;
}

int main () {
  scan(n);
  for (int i=0; i<n; i++){
    scan(x);
    int a = query(x, BIT1);
    int b = query(n - x + 1, BIT2);
    sum += min(a, b);
    update(x, 1, BIT1);
    update(n - x + 1, 1, BIT2);
  }
  printf("%1lu\n", sum);
}
