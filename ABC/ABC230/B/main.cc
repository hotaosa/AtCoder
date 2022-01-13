#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
    string s;
    cin >> s;
    if (s.length() == 1) { cout << "Yes" << endl; return 0; }
    if (s.length() == 2) { cout << (s == "oo" ? "No" : "Yes" ) << endl; return 0; }
    for (int i = 0; i < (int)s.length() - 2; ++i) {
        string sub = s.substr(i, 3);
        if (sub == "oxx" || sub == "xox" || sub == "xxo") continue;
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;    
    return 0;
}
