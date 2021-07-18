#include <iostream>

int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}

int main() {
  int n;
  std::cin >> n;

  int res;
  std::cin >> res;
  for (int i = 0; i < n - 1; ++i) {
    int a;
    std::cin >> a;
    res = gcd(res, a);
  }

  std::cout << res << std::endl;
  return 0;          
}
