#include <iostream>

int main() {
    long long n;
    std::cin >> n;
    long long res = 0LL;
    for (long long a = 1LL; a * a * a <= n; ++a) {
	for (long long b = a; a * b * b <= n; ++b) {
	    res += n / a / b - b + 1LL;
	}
    }
    std::cout << res << std::endl;
    return 0;
}
