#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<long long>> vc(n, std::vector<long long>(3));
  for (int i = 0; i < n; ++i) for (int j = 0; j < 3; ++j) std::cin >> vc[i][j];

  long long res = 0LL;
  for (int bit = 0; bit < 8; ++bit) {
    std::vector<long long> v;
    for (int i = 0; i < n; ++i) {
      long long sum = 0LL;
      for (int j = 0; j < 3; ++j) {
        sum += vc[i][j] * (bit & (1 << j) ? 1 : -1);
      }
      v.push_back(sum);
    }
    std::sort(v.begin(), v.end(), std::greater<long long>());
    long long score = 0LL;
    for (int i = 0; i < m; ++i) score += v[i];
    res = std::max(res, score);
  }

  std::cout << res << std::endl;
  return 0;  
}
