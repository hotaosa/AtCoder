#include <iostream>

int main() {
  long long a, c;
  int b;
  std::cin >> a >> b >> c;
  long long cc = 1;
  for (int i = 0; i < b; ++i) cc *= c;
  std::cout << (a < cc ? "Yes" : "No") << std::endl;
  return 0;
}
