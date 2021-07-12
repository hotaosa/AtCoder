#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  int n, k;
  std::cin >> n >> k;

  std::vector<long long> v;
  for (int i = 0; i < n; ++i) {
    long long a, b;
    std::cin >> a >> b;
    v.push_back(b);
    v.push_back(a - b);
  }

  std::sort(v.begin(), v.end(), std::greater<long long>());
  long long res = 0LL;
  for (int i = 0; i < k; ++i) res += v[i];
  std::cout << res << std::endl;
  return 0;
}
