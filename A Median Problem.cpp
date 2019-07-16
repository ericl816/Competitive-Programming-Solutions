#include <bits/stdc++.h>
#define ll long long
#define MAXN 110
#define INF 0x3f3f3f3f
#define min(a, b) (a) < (b) ? (a) : (b)
#define max(a, b) (a) < (b) ? (b) : (a)
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define mii map<int, int>
#define umii unordered_map<int, int>
using namespace std;

int N;
int arr[MAXN][MAXN];
vector<double> vec;

double findMedian(int a[], int n) {
    sort(a, a + n);
    if (n & 1) (double) (a[n >> 1]);
    return (double) ((a[(n - 1) >> 1] + a[n >> 1]) / 2.0);
}

int main () {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cin >> arr[i][j];
        }
    }
    for (int i=0; i<N; i++) sort(arr[i], arr[i] + N);
    for (int i=0; i<N; i++) vec.pb(arr[i][N >> 1]);
    sort(vec.begin(), vec.end());
    cout << round(vec[vec.size() >> 1]) << endl;
    return 0;
}