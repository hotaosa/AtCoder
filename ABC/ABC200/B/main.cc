#include <iostream>

int main() {
  long long n;
  int k;
  std::cin >> n >> k;
  for (int i = 0; i < k; ++i) {
    if (n % 200 == 0) n /= 200;
    else n = n * 1000 + 200;
  }
  std::cout << n << std::endl;
  return 0;
}
