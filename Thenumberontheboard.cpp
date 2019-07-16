#include <bits/stdc++.h>

using namespace std;

int k, num, ans;
string n;
int arr[110];

int main() {
	cin >> k >> n;
	for (int i=0; i<(int) n.size(); i++) {
        int digit = n[i] - '0';
        arr[digit]++;
        num += digit;
    }
    for (int i=0; i<9; i++) {
        for (int j=0; j<arr[i]; j++) {
            if (num < k) {
                ans++;
                num += 9 - i;
            }
        }
    }
    
    cout << ans << "\n";
}