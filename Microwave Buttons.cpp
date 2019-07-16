#include <bits/stdc++.h>
#define ll long long
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

string desired_time, buttons, ans, hours, minutes, seconds, res;
int total, num, minndiff = INF, val, diff;

int Calc (string s) { // Get total number of seconds
    return stoi(s.substr(0, 2)) * 3600 + stoi(s.substr(2, 2)) * 60 + stoi(s.substr(4, 2));
}

// Brute Force
inline void Check () {
    for (int i=0; i<num; i++) {
        for (int j=0; j<num; j++) {
            for (int k=0; k<num; k++) {
                for (int l=0; l<num; l++) {
                    for (int m=0; m<num; m++) {
                        for (int n=0; n<num; n++) {
                            res = buttons.substr(i, 1) + buttons.substr(j, 1) + buttons.substr(k, 1) + buttons.substr(l, 1) + buttons.substr(m, 1) + buttons.substr(n, 1);
                            val = Calc(res);
                            diff = abs(total - val);
                            if (diff < minndiff) {
                                minndiff = diff;
                                ans = res;
                            }
                        }
                    }
                }
            }
        }
    }
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    getline(cin, desired_time);
    getline(cin, buttons);
    
    num = buttons.length();
    if (num == 10) {
        cout << desired_time << endl;
        return 0;
    }
    hours = desired_time.substr(0, 2);
    minutes = desired_time.substr(3, 2);
    seconds = desired_time.substr(6, 2);
    total = stoi(hours) * 3600 + stoi(minutes) * 60 + stoi(seconds);
    
    Check();
    cout << ans.substr(0, 2) << ':' << ans.substr(2, 2) << ':' << ans.substr(4, 2) << endl;
    return 0;
}