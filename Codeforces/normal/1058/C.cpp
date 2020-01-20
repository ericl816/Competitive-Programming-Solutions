#include<bits/stdc++.h>
using namespace std;
int n, PSA[110], sum;
bool flag;
string s;
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> s;
    for (size_t i=0; i<s.size(); i++) {
        PSA[i] = s[i] - '0';
    }
    for (int i=1; i<n; i++) {
        PSA[i] += PSA[i - 1];
    }
    sum = PSA[n - 1];
    for (int i=2; i<=n; i++) {
        if (sum % i == 0) {
            int tmp = sum / i;
            int tmp1 = tmp;
            flag = 1;
            for(int j=0; j<n; j++) {
                if (PSA[j] > tmp) {
                    flag = 0;
                    break;
                }
                if (PSA[j] == tmp){
                    tmp += tmp1;
                }
            }
            if (flag){
                cout<<"YES\n";
                return 0;
            }
        }
    }
    cout << "NO\n";
    return 0;
}