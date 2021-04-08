#include <iostream>

int main() {
  int t;
  std::cin >> t;
  for (int i = 0; i < t; ++i) {
    long long n;
    std::cin >> n;
    if (n & 1LL) std::cout << "Odd" << std::endl;
    else if (n % 4LL == 0) std::cout << "Even" << std::endl;
    else std::cout << "Same" << std::endl;
  }
  return 0;
}
