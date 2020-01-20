#include <bits/stdc++.h>

using namespace std;

short N;

int main() {
    cin>>N;
    string input;
    
    while(N--)
    {
         
        int size= 0;
        cin>>input;
        for(short i = 0 ; i <input.length();i++)
        {
            for(short j = 1; i+j <=input.length();j++)
            {
                
		 std::size_t found = input.find(input.substr(i,j));
		 if(found != string::npos && found == i)
		    size++;           
                
            }
        }
        cout<<size+1<<"\n";
        
    }
    return 0;
}