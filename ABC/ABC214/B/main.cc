#include <iostream>

int main() {
  int s, t;
  std::cin >> s >> t;
  int res = 0;
  for (int a = 0; a <= 100; ++a) {
    for (int b = 0; b <= 100; ++b) {
      for (int c = 0; c <= 100; ++c) {
        if (a + b + c <= s && a * b * c <= t) ++res;
      }
    }
  }
  std::cout << res << std::endl;
  return 0;
}
