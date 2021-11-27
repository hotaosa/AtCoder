#include <bits/stdc++.h>
#include <atcoder/all>

int main() {
    char s[4];
    for (int i = 0; i < 4; ++i) std::cin >> s[i];

    bool possible = true;
    if (s[0] == '#' && s[1] == '.' && s[2] == '.' && s[3] == '#') possible = false;
    if (s[0] == '.' && s[1] == '#' && s[2] == '#' && s[3] == '.') possible = false;

    std::cout << (possible ? "Yes" : "No" ) << std::endl;
    return 0;
}
