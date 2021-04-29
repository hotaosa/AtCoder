#include <iostream>
#include <vector>

int main() {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> a(n), b(n);
  for (int i = 0; i < n; ++i) std::cin >> a[i];

  int diff = 0;
  for (int i = 0; i < n; ++i) {
    int b;
    std::cin >> b;
    diff += std::abs(a[i] - b);
  }

  std::cout << (diff <= k && ((diff & 1) == (k & 1)) ? "Yes" : "No") << std::endl;
  return 0;  
}
