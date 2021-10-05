#include <iostream>

int main() {
  int n;
  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    int a;
    std::cin >> a;
    std::cout << a;
    if (i < n - 1) std::cout << ",";
  }
  std::cout << std::endl;
  return 0;
}
