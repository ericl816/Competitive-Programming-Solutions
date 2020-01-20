#include <bits/stdc++.h>
using namespace std;
int n, a;
bool vis[100010];
int main(){
    cin>>n;
    int ptr=n;
    while(n--){
        cin>>a;
        vis[a]=1;
        while(vis[ptr]){
         cout << ptr << " ";
         --ptr;
        }
        cout << "\n";
    }
    return 0;
}