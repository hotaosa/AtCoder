#include <iostream>

int main() {
  int n;
  std::cin >> n;
  int res = 4;
  if (n > 125) res += 2;
  if (n > 211) res += 2;
  std::cout << res << std::endl;
  return 0;
}
