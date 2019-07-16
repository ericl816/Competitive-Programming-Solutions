#include "cave.h"
#include <cstdio>
#include <cstring>
using namespace std;
 
const int MAXN = 5001;
int status[MAXN] , door[MAXN] , guess[MAXN];
 
void exploreCave(int N){
    memset(door , -1 , sizeof(door));
    for(int n = 0 ; n < N ; n++){
         int r = tryCombination(status);
         int low = 0 , high = N - 1;
         while(low != high){
                    bool changed = false;
                    int a = low , b = (low + high) / 2;
                    for(int i = 0 ; i < N ; i++){
                        if(i >= a && i <= b){
                            if(door[i] != -1)
                                     guess[i] = status[i];
                            else {
                                    guess[i] = !status[i];
                                    changed = true;
                            }
                       }
                       else guess[i] = status[i];
                     }
                    int K = r;
                    if(changed) K = tryCombination(guess);
                    if(r == n){
                        if(K > n || K == -1)
                            high = b;
                        else low = b + 1;
                    }
                    else {
                        if(K == n) high = b;
                        else low = b + 1;
                    }
                 }
         door[low] = n;
         if(r == n) status[low] = !status[low];
        }
    answer(status , door);
}
