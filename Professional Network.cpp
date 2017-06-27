#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define q queue<int>
#define pq priority_queue<int>
char _;
using namespace std;
int N, A, B, num;
vector<pii> arr;
q keep;
pq give;

int main() {
    scan(N);
    for (int i=0; i<N; i++) {
        scan(A); scan(B);
        arr.pb(mp(A, B));
    }
    sort(arr.begin(), arr.end());
    for (int i=0; i<N; i++) {
        while (!keep.empty() && arr[keep.front()].f <= i) {
            give.push(arr[keep.front()].s);
            keep.pop();
        }
        if (arr[i].f <= i) {
            if (!give.empty() && give.top() > arr[i].s) {
                num += arr[i].s - give.top();
                give.pop();
                keep.push(i);
            }
        } 
        else {
            num += arr[i].s;
            if (!give.empty()) {
                num -= give.top();
                give.pop();
            }
            keep.push(i);
        }
    }
    printf("%d\n", num);
}
