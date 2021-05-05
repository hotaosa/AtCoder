#include <iostream>

int main() {
  int a, b;
  std::cin >> a >> b;
  int res = b - a;
  while ((a + res - 1) / res == b / res) --res;
  std::cout << res << std::endl;
  return 0;  
}
