#include <iostream>

int main() {
  int x;
  std::cin >> x;
  int res = -1;
  if (x < 90) res = 90 - x;
  if (x < 70) res = 70 - x;
  if (x < 40) res = 40 - x;

  if (res == -1) std::cout << "expert" << std::endl;
  else std::cout << res << std::endl;
  return 0;
}
