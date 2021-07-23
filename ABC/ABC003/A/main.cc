#include <iostream>

int main() {
  int n;
  std::cin >> n;
  n *= 10000;

  std::cout << (n + 10000) / 2 << std::endl;
  return 0;  
}
