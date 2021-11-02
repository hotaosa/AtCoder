#include <iostream>
#include <vector>

int main() {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> a(n), b(n);
  for (int i = 0; i < n; ++i) std::cin >> a[i];
  for (int i = 0; i < n; ++i) std::cin >> b[i];

  int d_sum = 0;
  for (int i = 0; i < n; ++i) d_sum += std::max(a[i] - b[i], b[i] - a[i]);
  std::cout << (k < d_sum || (k - d_sum) & 1 ? "No" : "Yes") << std::endl;
  return 0;
}
