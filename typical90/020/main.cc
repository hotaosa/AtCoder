#include <iostream>

int main() {
  long long a, b, c;
  std::cin >> a >> b >> c;
  long long d = 1;
  for (long long i = 0; i < b; ++i) d *= c;
  std::cout << (a < d ? "Yes" : "No") << std::endl;
  return 0;  
}
