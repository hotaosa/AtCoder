#include <bits/stdc++.h>
#include <atcoder/all>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;
        std::string s1, s2, s3;
        std::cin >> s1 >> s2 >> s3;

        std::string res(n, '0');
        res += std::string(n, '1');
        res += '0';
        std::cout << res << std::endl;
    }
    return 0;
}