#include <bits/stdc++.h>
#include <atcoder/all>

int main() {
    std::string s;
    std::cin >> s;
    int len = s.length();

    bool possible = true;

    std::string t = "";
    for (char c : s) if (c != 'A') t += c;
    if (t != "KIHBR") possible = false;

    bool find = false;
    for (int i = 0; i < len - 2; ++i) if (s.substr(i, 3) == "KIH") find = true;
    possible &= find;

    find = false;
    for (int i = 0; i < len - 1; ++i) if (s.substr(i, 2) == "AA") find = true;
    possible &= !find;

    std::cout << (possible ? "YES" : "NO" ) << std::endl;    
    return 0;
}
