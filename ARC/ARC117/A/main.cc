#include <iostream>
#include <vector>

int main() {
  int a, b;
  std::cin >> a >> b;
  std::vector<int> res;
  long long suma = 0LL, sumb = 0LL;
  if (a >= b) {
    for (int i = 1; i <= a; ++i) {
      std::cout << i << " ";
      suma += i;
    }
    for (int i = 1; i < b; ++i) {
      std::cout << 0 - i << " ";
      sumb += i;
    }
    std::cout << sumb - suma << std::endl;
  } else {
    for (int i = 1; i <= b; ++i) {
      std::cout << 0 - i << " ";
      sumb += i;
    }
    for (int i = 1; i < a; ++i) {
      std::cout << i << " ";
      suma += i;
    }
    std::cout << sumb - suma << std::endl;
  }
  return 0;  
}
