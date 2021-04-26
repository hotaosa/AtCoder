#include <iostream>
#include <vector>

int main() {
  int x;
  std::cin >> x;
  std::vector<int> nums(4);
  for (int i = 3; i >= 0; --i) {
    nums[i] = x % 10;
    x /= 10;
  }

  std::vector<bool> plus(3);
  for (int bit = 0; bit < (1 << 3); ++bit) {
    int sum = nums[0];
    for (int i = 0; i < 3; ++i) {
      if (bit & (1 << i)) { sum += nums[i + 1]; plus[i] = true; }
      else { sum -= nums[i + 1]; plus[i] = false; }
    }
    if (sum == 7) break;
  }

  for (int i = 0; i < 3; ++i) std::cout << nums[i] << (plus[i] ? "+" : "-");
  std::cout << nums[3] << "=7" << std::endl;
  return 0;
}
