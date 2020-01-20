#include<iostream>
#include <stdio.h>
#include <math.h> 
#define ULL unsigned long long
#define LL long long
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

using namespace std;

ULL a, b;
LL diff1, diff2;
bool prime1 [1000000];
bool prime2 [20000100];

int main () {
scan(a);
scan(b);
diff1 = b-a;
diff2 = sqrt(b)+1;

for (int i=0; i<diff1; ++i)
  if (i + a > 3 && ((i+a) % 2 == 0 || (i + a) % 3 == 0))
    prime1[i] = true;
    
    for (int i=5; i<diff2; i += 6)
      for (int j=i; j<= i+2; j += 2)
        if (j < diff2 && !prime2[j]){
          for (int k= j * j; 0<=k && k<diff2; k += j)
            prime2[k] = true;
            
            for (int l= (int) (a / j*j - a); l<diff1; l += j)
              if (l + a != j && l >= 0)
                prime1[l] = true;
        }
        LL cnt = 0;
        for (int i=0; i<diff1; i++)
          if (!prime1[i])
            cnt++;
            
        cout << cnt << "\n";
}