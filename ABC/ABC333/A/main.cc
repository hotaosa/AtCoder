#include <iostream>
#include <string>

int main() {
  int n;
  std::cin >> n;
  std::cout << std::string(n, '0' + n) << std::endl;
  return 0;
}
