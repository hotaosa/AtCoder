#include <iostream>

int main() {
  const long long INF = 1LL << 60;
  
  long long red, blue, x, y;
  std::cin >> red >> blue >> x >> y;

  auto possible = [&](long long mid) -> bool {
    if (red < mid || blue < mid) return false;
    return ((red - mid) / (x - 1) + (blue - mid) / (y - 1) >= mid);
  };

  long long r = INF, l = 0LL;
  while (r - l > 1LL) {
    long long mid = (r + l) / 2LL;
    if (possible(mid)) l = mid;
    else r = mid;
  }

  std::cout << l << std::endl;
  return 0;  
}
