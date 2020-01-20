#include<bits/stdc++.h>
#define pb push_back
#define ull unsigned long long 
#define INF 0x3f3f3f3f
using namespace std;

ull N, x, y, num = 0;
vector<pair<int, int>> xcoor, ycoor;

int main() {
    scanf("%llu", &N);
    for(int i=0; i<N; i++) {
        scanf("%llu %llu", &x, &y);
        xcoor.pb({ x, y });
        ycoor.pb({ y, x });
    }
    sort(xcoor.begin(), xcoor.end());
    sort(ycoor.begin(), ycoor.end());

    for(pair<int, int> next : xcoor) {
        auto xidx = lower_bound(ycoor.begin(), ycoor.end(), pair<int, int>{ next.second, next.first });
        auto xs = lower_bound(ycoor.begin(), ycoor.end(), pair<int, int>{ next.second, -INF });
        auto xe = lower_bound(ycoor.begin(), ycoor.end(), pair<int, int>{ next.second, INF });
        auto yidx = lower_bound(xcoor.begin(), xcoor.end(), pair<int, int>{ next.first, next.second });
        auto ys = lower_bound(xcoor.begin(), xcoor.end(), pair<int, int>{ next.first, -INF });
        auto ye = lower_bound(xcoor.begin(), xcoor.end(), pair<int, int>{ next.first, INF });
        num += (ull) ((xidx - xs) * (xe - xidx - 1) * (yidx - ys) * (ye - yidx - 1)) << 1;
    }
    printf("%llu\n", num);
}