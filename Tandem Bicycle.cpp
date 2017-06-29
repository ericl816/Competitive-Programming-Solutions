#include <iostream>
#include <algorithm>
using namespace std;

int d[105], p[105], type, people, sum = 0;

int main() {   
    scanf("%d \n %d \n", &type, &people);
    for (int i=0; i<people; i++) scanf("%d ", &d[i]);
    for (int i=0; i<people; i++) scanf("%d ", &p[i]);
    sort(d, d + people); 
    sort(p, p + people);
    if (type) 
        for (int i=0; i<people; i++) sum += max(d[i], p[i]);
    else 
        for (int i=0; i<people; i++) sum += max(d[people - 1 - i], p[i]);
    
    printf("%d\n", sum); 
