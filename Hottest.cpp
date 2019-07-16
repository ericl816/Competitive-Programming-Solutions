#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, k, x;
ll sum, mx;
deque<int> cur;

int main() {
    cin >> n >> k;
    while (n--) {
        cin >> x;
        sum += x;
        cur.push_back(x);
        while (cur.size() > k) {
            sum -= cur.front();
            cur.pop_front();
        }
        mx = max(mx, sum);
    }
    cout << mx << endl;
}
