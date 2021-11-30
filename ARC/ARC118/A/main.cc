#include <iostream>

int main() {
    long long t, n;
    std::cin >> t >> n;
    std::cout << (100LL + t) * ((100LL * n + t - 1LL) / t) / 100LL -1LL << std::endl;
    return 0;
}
