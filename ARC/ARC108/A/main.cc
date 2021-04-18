#include <iostream>

int main() {
  long long s, p;
  std::cin >> s >> p;
  bool exist = false;
  for (long long n = 1; n * n <= p; ++n) {
    if (p % n == 0 && n + p / n == s) exist = true; 
  }
  std::cout << (exist ? "Yes" : "No") << std::endl;
  return 0;
}
