#include <iostream>
#include <cmath>

int main() {
  double d;
  std::cin >> d;

  int x = std::floor(d);
  int y = (int)(d * 10) % 10;

  std::string add = "";
  if (y <= 2) add = "-";
  else if (y >= 7) add = "+";

  std::cout << x << add << std::endl;
  return 0;
}
