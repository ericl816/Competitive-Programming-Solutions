#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define ull unsigned long long
#define MAXN 1000010
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define min(a, b) (a) < (b) ? (a) : (b)
#define max(a, b) (a) < (b) ? (b) : (a)
#define vi vector<int>
#define vll vector<ll>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define mii map<int, int>
#define umii unordered_map<int, int>
#define allof(x) x.begin(), x.end()
#define DEBUG 1
// #define NOT_DMOJ 0
#ifdef DEBUG
    #define D(x...) printf(x)
#else
    #define D(x...)
#endif
using namespace std;

inline int GCD (int a, int b) { return b == 0 ? a : GCD(b, a % b); }
inline int LCM (int a, int b) { return a * b / GCD(a, b); }
inline ll PowMod (ll a, ll b, ll mod) { ll val = 1; while (b) { if (b & 1) val = (val * a) % mod; a = (a * a) % mod; b >>= 1; } return val; }

int TEST_CASES = 10;
int score;
string s, ans, s1 = "abcdefghijklmnopqrstuvwxyz", s2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ", s3 = "zyxwvutsrqponmlkjihgfedcba", s4 = "ZYXWVUTSRQPONMLKJIHGFEDCBA", s5 = "0123456789", s6 = "9876543210";

inline bool substring (string ss, string sss) {
    size_t ind = sss.find(ss);
    if (ind != string::npos) return 1;
    return 0;
}

inline bool isSymbol (char c) {
    return (!isupper(c) && !islower(c) && !isdigit(c));
}

inline void Do_Test_Cases () {
    while (TEST_CASES--) {
        cin >> s;
        score = 4 * s.length();
        // D("%d\n", score);
        if (s.length() >= 8) {
            bool upper = 0, lower = 0, digit = 0, symb = 0;
            int cnt = 0;
            for (auto i : s) upper |= isupper(i), lower |= islower(i), digit |= isdigit(i), symb |= isSymbol(i);
            cnt = upper + lower + digit + symb;
            if (cnt >= 3) {
                score += 2 * cnt;
                score += 2;
            }
            // D("%d\n", score);
        }
        int upper = 0, lower = 0, digits = 0, symbs = 0;
        for (auto i : s) {
            upper += isupper(i), lower += islower(i), digits += isdigit(i), symbs += isSymbol(i);
        }
        if (upper > 0) score += (s.length() - upper) * 2;
        if (lower > 0) score += (s.length() - lower) * 2;
        // D("%d\n", score);
        if (digits < s.length()) score += 4 * digits;
        // D("%d\n", score);
        score += 6 * symbs;
        // D("%d\n", score);
        digits = symbs = 0;
        for (size_t i=1; i<s.size() - 1; i++) {
            digits += isdigit(s[i]), symbs += isSymbol(s[i]);
        }
        score += 2 * (digits + symbs);
        // D("%d\n", score);
        bool letters = 1, digit = 1;
        for (auto i : s) {
            letters &= (islower(i) || (isupper(i))), digit &= isdigit(i);
        }
        if (letters) score -= s.length();
        if (digit) score -= s.length();
        // D("%d\n", score);
        int cnt1 = 1, cnt2 = 1, cnt3 = 1;
        for (size_t i=0; i<s.size() - 1; i++) {
            if (isupper(s[i]) && isupper(s[i + 1])) cnt1++;
            if (islower(s[i]) && islower(s[i + 1])) cnt2++;
            if (isdigit(s[i]) && isdigit(s[i + 1])) cnt3++;
        }
        score -= 2 * (max(0, cnt1 - 1));
        score -= 2 * (max(0, cnt2 - 1));
        score -= 2 * (max(0, cnt3 - 1));
        // D("%d\n", score);
        int longest1 = 0, longest2 = 0;
        for (size_t i=0; i<s.size(); i++) {
            for (size_t j=1; j<=s.size() - i; j++) {
                string ss = s.substr(i, j);
                if (ss.length() > 2 && (substring(ss, s1) || substring(ss, s2) || substring(ss, s3) || substring(ss, s4))) {
                    longest1 = max(longest1, ss.length());
                }
            }
        }
        // D("%d\n", longest1);
        score -= 3 * (max(0, longest1 - 2));
        // D("%d\n", score);
        for (size_t i=0; i<s.size(); i++) {
            for (size_t j=1; j<=s.size() - i; j++) {
                string ss = s.substr(i, j);
                if (ss.length() > 2 && (substring(ss, s5) || substring(ss, s6))) {
                    longest2 = max(longest2, ss.length());
                }
            }
        }
        score -= 3 * (max(0, longest2 - 2));
        if (score < 0) score = 0;
        else if (score > 100) score = 100;
        if (score >= 0 && score <= 20) ans = "Very Weak";
        else if (score >= 21 && score <= 40) ans = "Weak";
        else if (score >= 41 && score <= 60) ans = "Good";
        else if (score >= 61 && score <= 80) ans = "Strong";
        else if (score >= 81 && score <= 100) ans = "Very Strong";
        cout << ans << " " << "(score = " << score << ")\n";
    }
}

int main () {
    #ifdef NOT_DMOJ
    freopen("DATA11.txt", "r", stdin);
    freopen("DATA11out.txt", "w", stdout);
    #endif // NOT_DMOJ
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Do_Test_Cases();
    return 0;
}