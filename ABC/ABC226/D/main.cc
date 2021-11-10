#include <iostream>
#include <vector>
#include <set>

int main() {
  int n;
  std::cin >> n;
  std::vector<int> x(n), y(n);
  for (int i = 0; i < n; ++i) std::cin >> x[i] >> y[i];

  int res = 0;
  std::set<double> se;
  for (int i = 0; i < n - 1; ++i) {
    for (int j = i + 1; j < n; ++j) {
      int dx = x[j] - x[i], dy = y[j] - y[i];
      if (se.insert(dx ? (double)dy / dx : 1e10).second) res += 2;
    }
  }

  std::cout << res << std::endl;
  return 0;  
}
