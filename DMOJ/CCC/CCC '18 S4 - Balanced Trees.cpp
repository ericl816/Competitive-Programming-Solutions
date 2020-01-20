#include <bits/stdc++.h>
  

using namespace std;

unordered_map<int, long int> mem;

 long int calc(int num)
{
     long int sum=0;
	if(num <= 2)
	    return mem[num] = 1;
	    
	  if (mem.count(num)) return mem[num];    
	int a,b,d;
	a=num;
	
	d= 1;
	while(a!=1)
	{
	    d = num / a;
	    b = num/(d+1);
	      //if (!mem.count(d)) calc(d);
	    sum += (a-b) * calc(d);
	    
	    a = b ;
	}
return mem[num] = sum;
	
}


int main() {

ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	
int N;
cin>>N;
cout<<calc(N);












	return 0;

}