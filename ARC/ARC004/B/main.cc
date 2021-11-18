#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    int sum = 0, ma = 0;
    for (int i = 0; i < n; ++i) {
        int d;
        std::cin >> d;
        sum += d;
        ma = std::max(ma, d);
    }

    std::cout << sum << std::endl;
    std::cout << std::max(0, ma - (sum - ma)) << std::endl;    
    return 0;
}
