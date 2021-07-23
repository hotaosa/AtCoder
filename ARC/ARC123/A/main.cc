#include <iostream>

int main() {
  long long a1, a2, a3;
  std::cin >> a1 >> a2 >> a3;
  long long a = a2 * 2 - a1 - a3;

  if (a == 0LL) std::cout << "0" << std::endl;
  else if (a > 0LL) std::cout << a << std::endl;
  else {
    a = a * (-1);
    if (a & 1) std::cout << a / 2 + 2 << std::endl;
    else std::cout << a / 2 << std::endl;
  }
  return 0;
}
