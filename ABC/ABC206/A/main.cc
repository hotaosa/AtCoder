#include <iostream>
#include <cmath>

int main() {
  int n;
  std::cin >> n;
  int price = std::floor(1.08 * n);
  if (price < 206) std::cout << "Yay!" << std::endl;
  else if (price == 206) std::cout << "so-so" << std::endl;
  else std::cout << ":(" << std::endl;
  return 0;
}
