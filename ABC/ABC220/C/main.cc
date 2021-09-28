#include <iostream>
#include <vector>

int main() {
  int n;
  std::cin >> n;
  std::vector<long long> a(n);
  for (int i = 0; i < n; ++i) std::cin >> a[i];
  long long x;
  std::cin >> x;

  for (int i = 0; i < n - 1; ++i) a[i + 1] += a[i];
  long long res = x / a.back() * n;
  x %= a.back();

  for (int i = 0; i < n; ++i) {
    if (a[i] > x) {
      res += i + 1;
      break;
    }
  }

  std::cout << res << std::endl;
  return 0;
}
