#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
using namespace std;
int N;
ll i;
int main() {
   scan(N);
   for (int j=0; j<N; j++){
    scan(i);
    printf("%s\n", (i & (i - 1) ? "F" : "T"));
   }
}
