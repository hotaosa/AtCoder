#include <iostream>
#include <vector>

int main() {
  int m, k;
  std::cin >> m >> k;
  if (m < 2) {
    if (k > 0) std::cout << "-1" << std::endl;
    else {
      for (int i = 0; i < (1 << m); ++i) std::cout << i << " " << i << " ";
      std::cout << std::endl;
    }
    return 0;
  }

  if (k >= (1 << m)) { std::cout << "-1" << std::endl; return 0; }
  for (int i = 0; i < (1 << m); ++i) if (i != k) std::cout << i << " ";
  std::cout << k << " ";
  for (int i = (1 << m) - 1; i >= 0; --i) if (i != k) std::cout << i << " ";
  std::cout << k << std::endl;
  return 0;
}
