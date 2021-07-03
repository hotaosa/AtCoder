#include <iostream>

int main() {
  double a, b;
  std::cin >> a >> b;
  printf("%.10f\n", a / 100.0 * b);
  return 0;
}
