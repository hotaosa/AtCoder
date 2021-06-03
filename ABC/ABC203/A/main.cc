#include <iostream>

int main() {
  int a, b, c;
  std::cin >> a >> b >> c;
  if (a == b) std::cout << c;
  else if (a == c) std::cout << b;
  else if (b == c) std::cout << a;
  else std::cout << "0";
  std::cout << std::endl;
  return 0;
}
