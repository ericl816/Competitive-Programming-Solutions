#include <stdio.h>
using namespace std;

int k, n, ans;

int main() {
    scanf("%d %d", &n, &k);
    for (int i=0; i<=k; n*=10, i++) ans += n;
    printf("%d\n", ans);
    return 0;
}