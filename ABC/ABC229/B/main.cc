#include <bits/stdc++.h>
#include <atcoder/all>

int main() {
    long long a, b;
    std::cin >> a >> b;

    bool exist = false;
    while (a && b && !exist) {
        if ((a % 10) + (b % 10) > 9) exist = true;
        a /= 10;
        b /= 10;
    }

    std::cout << (exist ? "Hard" : "Easy" ) << std::endl;
    return 0;
}
