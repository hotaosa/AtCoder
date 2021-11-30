#include <bits/stdc++.h>
#include <atcoder/all>

int main() {
    int x;
    std::cin >> x;

    int res = 1, cur = x;
    while (cur) { cur = (cur + x) % 360; ++res; }

    std::cout << res << std::endl;
    return 0;
}
