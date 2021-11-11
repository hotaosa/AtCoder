#include <iostream>

long long gcd(long long a, long long b) {
  if (b == 0LL) return a;
  else return gcd(b, a % b);
}

int main() {
  constexpr long long INF = 1e18;
  long long a, b;
  std::cin >> a >> b;
  long long g = gcd(a, b);
  if (a / g > INF / b) std::cout << "Large" << std::endl;
  else std::cout << a / g * b << std::endl;
  return 0;
}
