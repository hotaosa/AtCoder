#include <iostream>

int main() {
  int a, b;
  std::cin >> a >> b;
  int c = a - b;
  int res = 1;
  for (int i = 0; i < c; ++i) res *= 32;
  std::cout << res << std::endl;
  return 0;  
}
