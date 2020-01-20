#include <bits/stdc++.h>
using namespace std;
int n;
bool f (int N) {
    if (N == 1) return 0;
    bool flag = 0;
    for (int i=2; i<=sqrt(N); i++) {
        if (N % i == 0) {
            flag = 1;
            break;
        }
    }
    return !flag;
}
int main() {
    cin >> n;
    cout << f(n) << "\n";
    return 0;
}