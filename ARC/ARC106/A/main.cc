#include <bits/stdc++.h>
#include <atcoder/all>

int main() {
    long long n;
    std::cin >> n;

    int a = 1;
    long long x = 3;
    while (x < n) {
        int b = 1;
        long long y = 5;
        while (x + y <= n) {
            if (x + y == n) { std::cout << a << " " << b << std::endl; return 0; }
            y *= 5;
            ++b;
        }
        x *= 3;
        ++a;
    }
    std::cout << "-1" << std::endl;
    return 0;
}
