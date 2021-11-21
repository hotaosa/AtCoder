#include <bits/stdc++.h>
#include <atcoder/all>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(n, 0);
    int xorSum = 0;
    for (auto &p : a) { std::cin >> p; xorSum ^= p; }

    for (auto &p : a) std::cout << (p ^ xorSum) << std::endl;
    return 0;
}
