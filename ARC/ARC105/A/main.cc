#include <iostream>
#include <vector>

int main() {
  std::vector<int> a(4);
  int tot = 0;
  for (int i = 0; i < 4; ++i) { std::cin >> a[i]; tot += a[i]; }

  bool possible = false;
  
  for (int bit = 1; bit < (1 << 4); ++bit) {
    int sum = 0;
    for (int i = 0; i < 4; ++i) {
      if (bit & (1 << i)) sum += a[i];
    }
    if (sum == tot - sum) possible = true;
  }

  std::cout << (possible ? "Yes" : "No") << std::endl;
  return 0;
}
