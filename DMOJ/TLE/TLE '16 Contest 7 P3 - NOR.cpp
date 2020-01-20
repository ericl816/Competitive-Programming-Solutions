#include<iostream>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

using namespace std;
int n, a, q, x, y, arr [1000001];
bool b [1000001];
bool find (int a, int b) {
  return a == b ? 1 : 0;
}

int main () {
scan(n);
for (int i=0; i<n; i++) {
scan(a); b[i] = a;
if (!b[i]) arr[i+1] = arr[i];
else arr[i+1] = i+1;
}
scan(q);
for (int i=0; i<q; i++) {
  scan(x); scan(y);
  if (find(arr[y], x)) printf("%d\n", (~abs(x - y) & 1));
  else printf("%d\n", abs(y - max(arr[y], x)) & 1);
}
}