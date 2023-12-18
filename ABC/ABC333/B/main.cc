#include <iostream>

int Dist(char a, char b) {
  int d = std::abs((a - 'A') - (b - 'A'));
  return std::min(d, 5 - d);
}

int main() {
  char a, b, c, d;
  std::cin >> a >> b >> c >> d;
  std::cout << (Dist(a, b) == Dist(c, d) ? "Yes" : "No" ) << std::endl;
  return 0;
}