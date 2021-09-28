#include <iostream>
#include <string>

int main() {
  int k;
  std::string sa, sb;
  std::cin >> k >> sa >> sb;

  std::cout << stoll(sa, nullptr, k) * stoll(sb, nullptr, k) << std::endl;
  return 0;
}
