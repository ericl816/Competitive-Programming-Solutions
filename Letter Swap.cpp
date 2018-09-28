#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXM 300
#define MAXN 1000010
#define SIZE 20
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

int w[1 << (SIZE+1)];

void insert(int x, int val) {
   int v = (1 << SIZE) + x;
   w[v] = val;
   while (v != 1){
     v /= 2;
     w[v] = w[2 * v] + w[2 * v + 1];
   }
}

int query(int a, int b){
   int va = (1 << SIZE) + a;
   int vb = (1 << SIZE) + b;
   int wyn = w[va];
   if (va != vb) 
     wyn += w[vb];

   while (va / 2 != vb / 2) {
     if (va % 2 == 0) wyn += w[va + 1]; 
     if (vb % 2 == 1) wyn += w[vb - 1]; 
     va /= 2; vb /= 2;
   }
   return wyn;
}

ll wynik;
int n, pos, temp;
vi tab[MAXM];
char s[MAXN];

int main(){
  scanf("%d", &n);
  scanf("%s", s);
  for (int i=n - 1; i>=0; i--) tab[int(s[i])].pb(i);
  scanf("%s", s);
  for (int i=0; i<n; i++) {
    pos = tab[int(s[i])].back();
    tab[int(s[i])].pop_back();
    insert(pos, 1);
    pos += query(pos + 1, MAXN);
    wynik += pos - i;
  }
  return !printf("%lld\n", wynik);
}