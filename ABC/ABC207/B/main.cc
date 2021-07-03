#include <iostream>

int main() {
  long long a, b, c, d;
  std::cin >> a >> b >> c >> d;

  if (b < c * d) std::cout << (a + c * d - b - 1) / (c * d - b) << std::endl;
  else std::cout << "-1" << std::endl;
  return 0;  
}
