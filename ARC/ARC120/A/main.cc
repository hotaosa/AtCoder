#include <bits/stdc++.h>
#include <atcoder/all>

int main() {
    int n;
    std::cin >> n;

    long long sum = 0LL, doubleSum = 0LL, ma = 0LL;
    for (int i = 0; i < n; ++i) {
        long long a;
        std::cin >> a;
        sum += a;
        doubleSum += sum;
        ma = std::max(ma, a);
        std::cout << ma * (i + 1) + doubleSum << std::endl;
    }    
    return 0;
}
