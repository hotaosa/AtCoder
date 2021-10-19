#include <iostream>

bool is_possible2(long long x, long long y, long long a, long long b) {
  return (a + x - 1LL) / x + (b + x - 1LL) / x <= y;
}

bool is_possible(long long x, long long y, long long a, long long b, long long c) {
  long long ny = y - (a + x - 1LL) / x;
  if (ny <= 0LL) return false;
  return is_possible2(x, ny, b, c) || is_possible2(ny, x, b, c);
};

int main() {
  long long x, y, a, b, c;
  std::cin >> x >> y >> a >> b >> c;

  bool possible = false;
  possible |= is_possible(x, y, a, b, c);
  possible |= is_possible(x, y, b, c, a);
  possible |= is_possible(x, y, c, a, b);
  possible |= is_possible(y, x, a, b, c);
  possible |= is_possible(y, x, b, c, a);
  possible |= is_possible(y, x, c, a, b);

  std::cout << (possible ? "Yes" : "No") << std::endl;
  return 0;  
}
