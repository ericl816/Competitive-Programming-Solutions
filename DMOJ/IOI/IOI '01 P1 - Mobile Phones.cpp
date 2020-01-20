#include<stdio.h>
#define scan(x) do{while((_n=getchar_unlocked())<45);if(_n-45)x=_n;else x=getchar_unlocked();for(x-=48;47<(_=getchar_unlocked());x=(x<<3)+(x<<1)+_-48);if(_n<46)x=-x;}while(0)
char _, _n;
using namespace std;
const int MAXN = 1030;
int N, s, x, y, a, x1, y1, x2, y2, BIT[MAXN][MAXN];

void update(int x, int y, int v) {
    for (; x < MAXN; x += (x & -x)) {
        for (int y1 = y; y1 < MAXN; y1 += (y1 & -y1))
            BIT[x][y1] += v;
    }
}

int query(int x, int y) {
    int sum = 0;
    for (; x > 0; x -= (x & -x)) {
        for (int y1 = y; y1 > 0; y1 -= (y1 & -y1))
            sum += BIT[x][y1];
    }
    return sum;
}


int query(int x1, int y1, int x2, int y2){
    return query(x2, y2) - query(x2, y1 - 1) - query(x1 - 1, y2) + query(x1 - 1, y1 - 1);
}

int main() {
    while (1) {
        scan(s);
        if (s == 0) scan(N);
        else if (s == 1) {
            scan(x); scan(y); scan(a);
            update(x + 1, y + 1, a);
        }
        else if (s == 2) {
            scan(x1); scan(y1); scan(x2); scan(y2);
            x1++; x2++; y1++; y2++;
            printf("%d\n", query(x1, y1, x2, y2));
        }
        else break;
    }
}