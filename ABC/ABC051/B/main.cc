#include <iostream>

int main() {
  int k, s;
  std::cin >> k >> s;

  int res = 0;
  for (int x = 0; x <= k; ++x) {
    for (int y = 0; y <= k; ++y) {
      int z = s - x - y;
      if (z >= 0 && z <= k) ++res;
    }
  }
  
  std::cout << res << std::endl;
  return 0;  
}
