#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define MAXN 1000000
#define umii unordered_map<int, int>
#define getchar() (*_pbuf ? *_pbuf++ : (_buf[fread_unlocked(_pbuf = _buf, 1, 16384, stdin)] = 0, *_pbuf++))
char _buf[16385], *_pbuf = _buf;
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> bbst;

static inline int read() {
    int c, o = 0;
    while ((c = getchar()) < '0');
    do o = (o << 1) + (o << 3) + c - '0';
    while ((c = getchar()) >= '0');
    return o;
}

int N, a, b;
int rnk[MAXN];
char op;
umii player;
bbst bst;

int main () {
    N = read();
    for (int i=0; i<N; i++) {
        op = getchar();
        switch (op) {
            case 'N':
                a = read();
                b = read();
                rnk[a] = b;
                player[b] = a;
                bst.insert(b);
                break;
            case 'M':
                a = read();
                b = read();
                bst.erase(bst.find(rnk[a]));
                player[rnk[a]] = 0;
                rnk[a] = b;
                player[b] = a;
                bst.insert(b);
                break;
            case 'Q':
                a = read();
                printf("%d\n", player[*bst.find_by_order(bst.size() - a)]);
                break;
        }
    }
    return 0;
}