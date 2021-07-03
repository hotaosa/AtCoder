#include <iostream>

int main() {
  long long a, b;
  int c;
  std::cin >> a >> b >> c;
  if (!(c & 1)) {
    a = a * a;
    b = b * b;
  }

  if (a == b) std::cout << "=" << std::endl;
  else if (a > b) std::cout << ">" << std::endl;
  else std::cout << "<" << std::endl;

  return 0;  
}
