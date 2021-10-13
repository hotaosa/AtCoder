#include <iostream>

int main() {
  int n, p;
  std::cin >> n >> p;
  int res = 0;
  while (n--) {
    int a;
    std::cin >> a;
    if (a < p) ++res;
  }
  std::cout << res << std::endl;
  return 0;
}
