#include <iostream>

int main() {
  long long n;
  std::cin >> n;
  long long num = 1LL;
  int res = 0;
  while (num * 2LL <= n) {
    num *= 2LL;
    ++res;
  }
  std::cout << res << std::endl;
  return 0;
}
