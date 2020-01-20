#include <bits/stdc++.h>

using namespace std;
int N,A,B;
int main() {
    cin>>N>>A>>B;
    map<int,int> half;
    set<int> shells;
    while(A--)
    {
        int a;
        cin>>a;
        half[a]++;
        
    }
    while(B--)
    {
        int b;
        cin>>b;
        half[b]++;
        
        
    }
    int cnt = 0;
    for(int i = 1; i <= 1000000; i++)
    {
        
        if (half[i] >=2)
            cnt++;
    }
    cout<<N-cnt;
    return 0;
}