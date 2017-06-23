#include <bits/stdc++.h>
using namespace std;
int N, x, ans = 0;
int main() {
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> x;
        ans ^= x;
    }
    printf("%d\n", ans);
}
