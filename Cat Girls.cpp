#include<bits/stdc++.h>
#define ull unsigned long long 
#define max(a, b) ((a) < (b) ? (b) : (a))
using namespace std;
const int MAXN = 500010;
int N, idx = 1;
char ch;
ull W, p, c, temp, pose[MAXN], cute[MAXN], DP[MAXN];

int main() {
    scanf("%d %llu", &N, &W);
    for (int i=0; i<N; i++){
        scanf(" %c", &ch);
        if (ch == 'A') {
            scanf("%llu %llu", &p, &c);
            pose[idx] = pose[idx - 1] + p;
            cute[idx] = cute[idx - 1] + c;
            int lo = 0, high = idx;
            while (lo <= high) {
                int mid = (lo + high) >> 1;
                temp = pose[idx] - pose[mid];
                if (W >= temp) high = mid - 1;
                else lo = mid + 1;
            }
            DP[idx] = max(DP[idx - 1], cute[idx] - cute[lo]);
            printf("%llu\n", DP[idx]);
            idx++;
        }
        else idx--;
    }
}
