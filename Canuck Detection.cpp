#include <iostream>
#include <string>
using namespace std;

string S, s = "our";

int main() {
    getline(cin, S);
    int pos = -1;
    bool ok = 1;
    for (int i=0; ok && i!=s.size(); i++) ok = (pos = S.find(s[i], pos + 1)) != string::npos;
    cout << (ok ? "Y" : "N") << endl;
    return 0;
}