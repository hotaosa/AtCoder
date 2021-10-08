#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  const long long INF = 1LL << 60;
  int n;
  std::cin >> n;
  std::vector<long long> a(n);
  for (int i = 0; i < n; ++i) std::cin >> a[i];
  a.push_back(INF);
  a.push_back(-INF);
  std::sort(a.begin(), a.end());

  int q;
  std::cin >> q;
  for (int i = 0; i < q; ++i) {
    long long b;
    std::cin >> b;
    auto p = std::lower_bound(a.begin(), a.end(), b);
    std::cout << std::min(*p - b, b - *(p - 1)) << std::endl;
  }

  return 0;  
}
