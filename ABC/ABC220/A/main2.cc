#include <iostream>

int main() {
  int a, b, c;
  std::cin >> a >> b >> c;

  for (int i = a; i <= b; ++i) {
    if (i % c == 0) {
      std::cout << i << std::endl;
      return 0;
    }
  }
  std::cout << "-1" << std::endl;
  return 0;
}
