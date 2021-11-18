#include <iostream>
#include <string>

int solve(std::string s) {
    int len = s.length();
    if (s > "atcoder") return 0;
    int pos = -1;
    for (int i = len - 1; i >= 0; --i) if (s[i] != 'a') pos = i;

    if (pos == -1) return -1;
    int ret = pos;
    if (s[pos] > 't') --ret;
    return ret;    
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        std::string s;
        std::cin >> s;
        std::cout << solve(s) << std::endl;
    }
    return 0;
}
