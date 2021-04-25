#include <iostream>

long long gcd(long long a, long long b) {
  if (b == 0) return a;
  else return gcd(b, a % b);
}

int main() {
  long long a, b, c;
  std::cin >> a >> b >> c;
  long long g = gcd(a, gcd(b, c));
  std::cout << (a + b + c) / g - 3 << std::endl;
  return 0;
}
