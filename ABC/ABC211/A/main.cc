#include <iostream>

int main() {
  double a, b;
  std::cin >> a >> b;
  printf("%.10f\n",(a - b) / 3.0 + b);
  return 0;
}
