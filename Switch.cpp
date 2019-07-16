#include <bits/stdc++.h>
using namespace std;

bool exist[1 << 25];
map < int, int > ma;
queue < int > que;
int K, a, start, temp, counter, ind;

int main() {
    scanf(" %d", &K);
    for (int i = 0; i < K; i++) {
        scanf(" %d", &a);
        start <<= 1;
        start += a;
    }
    que.push(start);
    exist[start] = true;
    ma[start] = 0;
    while(!que.empty()) {
        a = que.front(); que.pop();
        if (a == 0)
            break;
        for (int i = 0; i < K; ++i) {
            if (!(a & (1 << i))) {
                temp = (a | (1 << i));
                counter = 0;
                for (int j = 0; j < K; ++j) {
                    if (temp & (1 << j)) {
                        if (!counter)
                            ind = j;
                        counter++;
                    } 
                    else {
                        if (counter >= 4) {
                            while (temp & (1 << ind)) {
                                temp &= ~(1 << ind);
                                ind++;
                            }
                            break;
                        }
                        counter = 0;
                    }
                }
                if (counter >= 4) {
                    while (temp & (1 << ind)) {
                        temp &= ~(1 << ind);
                            ind++;
                    }
                }
                if (!exist[temp]) {
                    exist[temp] = 1;
                    ma[temp] = ma[a] + 1;
                    que.push(temp);
                }
            }
        }
    }
    printf("%d", ma[0]);
}
