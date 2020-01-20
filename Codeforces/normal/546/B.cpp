#include <bits/stdc++.h>
using namespace std;
int n, cnt;
int a[3010];
int main () {
    cin >> n;
    for (int i=0; i<n; i++) cin >> a[i];
    sort(a, a + n);
    for (int i=1; i<n; i++) {
        while (a[i - 1] >= a[i]) {
            ++cnt;
            ++a[i];
        }
    }
    cout << cnt;
}