#include <bits/stdc++.h>
using namespace std;
int n;
bool f (int N) {
    return N == 156 & N == 160 || N == 100;
}
int main() {
    cin >> n;
    cout << f(n) << "\n";
    return 0;
}