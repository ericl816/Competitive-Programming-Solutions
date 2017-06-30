#include<bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define max(a,b) ((a) < (b) ? (b) : (a))
#define f first
#define s second
#define pii pair<int, int>
char _;
using namespace std;

const int MAXN = 1 << 22;
int N, M, i, S, num;
pii arr[MAXN]; 
char ch;

int main() {
    scan(N);
    scan(M);
    for(int i=1; i<=(1 << N); i++) {
      scan(arr[((1 << N) - 1) + i].f);
        arr[((1 << N) - 1) + i].s = i;
    }
    for(int i=(1 << N) - 1; i>=1; i--) arr[i] = max(arr[i << 1], arr[i << 1 | 1]);
    while(M--) {
        scanf("%s", &ch);
        if(ch == 'R') {
          scan(i);
          scan(S);
            arr[((1 << N) - 1) + i].f = S;
            for(int j=(((1 << N) - 1) + i) >> 1; j>=1; j >>= 1) arr[j] = max(arr[j << 1], arr[j << 1 | 1]);
        }
        else if (ch == 'S') {
            scan(i);
            num = 0;
            for(int j=(((1 << N) - 1) + i) >> 1; j>=1; j >>= 1)
                if(arr[j] == arr[((1 << N) - 1) + i]) num++;
                else break;
            printf("%d\n", num);
        }
        else printf("%d\n", arr[1].s);
    }
}
