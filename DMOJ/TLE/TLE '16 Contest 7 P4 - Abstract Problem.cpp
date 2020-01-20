#include <bits/stdc++.h>
#define ULL unsigned long long
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

using namespace std;

int main() {
    int T; 
    scan(T);
    ULL N;
    int ans;
    while(T--) {
        scan(N);
        ans = 0;
        while (N > 0) {
            if (N & 1){
                if (N & 2 && N ^ 3){
                    N++;
                }
                else{
                    N--;
                }
            }
            else{
                N = N >> 1;
            }
            ans++;
        }
        printf("%d\n", ans);
    }
}