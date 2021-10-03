#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  constexpr int INF = 1 << 30;
  int n;
  std::cin >> n;
  std::vector<int> v(n);
  for (int i = 0; i < n; ++i) std::cin >> v[i];

  std::vector<int> dp(n, INF);
  for (int i = 0; i < n; ++i) {
    *std::lower_bound(dp.begin(), dp.end(), v[i]) = v[i];
  }

  std::cout << std::lower_bound(dp.begin(), dp.end(), INF) - dp.begin() << std::endl;
  return 0;  
}
