#include <iostream>

int main() {
  int n;
  std::cin >> n;

  int a_ma = 0, b_mi = 1 << 30;
  for (int i = 0; i < n; ++i) {
    int a;
    std::cin >> a;
    a_ma = std::max(a_ma, a);
  }
  for (int i = 0; i < n; ++i) {
    int b;
    std::cin >> b;
    b_mi = std::min(b_mi, b);
  }
  std::cout << std::max(0, b_mi - a_ma + 1) << std::endl;
  return 0;  
}
