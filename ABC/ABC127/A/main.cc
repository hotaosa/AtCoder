#include <iostream>

int main() {
  int a, b;
  std::cin >> a >> b;
  int res = 0;
  if (a > 5) res += b / 2;
  if (a > 12) res += b / 2;
  std::cout << res << std::endl;
  return 0;  
}
