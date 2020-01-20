#include<bits/stdc++.h>
using namespace std;
int n,d,m,x,y;
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> d >> m;
    while(m--){
        cin >> x >> y;
        int tmp = abs(x - d);
        int tmp2 = n - abs(x - (n - d));
        if(y>=tmp&&y<=tmp2)cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}