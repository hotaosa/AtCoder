#include <iostream>

int main() {
  int a, b, c;
  std::cin >> a >> b >> c;
  if (a < b) a += 24;
  if (c < b) c += 24;
  std::cout << ((a - b) * (c - a) < 0 ? "Yes" : "No") << "\n";
  return 0;
}