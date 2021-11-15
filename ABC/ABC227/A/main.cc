#include <iostream>

int main() {
    int n, k, a;
    std::cin >> n >> k >> a;
    a -= 2;
    while (k--) {
	a = (a + 1) % n;
    }
    std::cout << a + 1 << std::endl;
    return 0;
}
