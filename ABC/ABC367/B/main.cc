#include <iostream>
#include <string>

int main() {
  std::string x;
  std::cin >> x;

  while (x.back() == '0') x.pop_back();
  if (x.back() == '.') x.pop_back();
  std::cout << x << "\n";

  return 0;
}