#include <iostream>

int main() {
  int n, x;
  std::cin >> n >> x;
  for (int i = 0; i < n; ++i) {
    int a;
    std::cin >> a;
    x -= a;
  }
  x += n / 2;

  std::cout << (x >= 0 ? "Yes" : "No") << std::endl;
  return 0;
}
