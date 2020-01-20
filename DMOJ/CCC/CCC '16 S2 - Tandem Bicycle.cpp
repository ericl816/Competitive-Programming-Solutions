#include <iostream>
#include<algorithm>
using namespace std;

int main()
{
    int question, n, total;
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> question >> n;
    total = 0;
    int first[n];
    int second[n];
    for(int i = 0; i < n; i++)
    {
        cin >> first[i];
    }
    for(int i = 0; i < n; i++)
    {
        cin >> second[i];
    }
    std::sort(first, first + n);
    std::sort(second,second+n);
    if(question == 1)
    {
        for(int i = 0; i < n; i++)
        {
            if(first[i]>= second[i])total = total + first[i];
            else total = total + second[i];

        }
    }
    else
    {
        for(int i = 0; i < n; i++)
        {
            if(first[i]>= second[n-1-i])total = total + first[i];
            else total = total + second[n-1-i];

        }
    }
    cout << total;
    return 0;
}